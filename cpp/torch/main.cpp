#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <torch/script.h>
#include <torch/torch.h>

using torch::indexing::None;
using torch::indexing::Slice;

auto tensor_options_ = torch::TensorOptions().device(torch::kCPU);

auto q = torch::tensor({{1e-5, 0.0, 0.0, 0.0, 0.0},
                        {0.0, 1e-5, 0.0, 0.0, 0.0},
                        {0.0, 0.0, 1e-8, 0.0, 0.0},
                        {0.0, 0.0, 0.0, 1.0, 0.0},
                        {0.0, 0.0, 0.0, 0.0, 0.01}}, tensor_options_.dtype(torch::kFloat32));

auto h = torch::tensor({{1.0, 0.0, 0.0, 0.0, 0.0},
                        {0.0, 1.0, 0.0, 0.0, 0.0},
                        {0.0, 0.0, 1.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0, 1.0, 0.0}}, tensor_options_.dtype(torch::kFloat32));

auto r = torch::tensor({{0.01, 0.0,   0.0, 0.0},
                        {0.0,  0.01,  0.0, 0.0},
                        {0.0,  0.0,   0.1, 0.0},
                        {0.0,  0.0,   0.0, 0.1}}, tensor_options_.dtype(torch::kFloat32)).square();

torch::Tensor gen_measurement(const torch::Tensor& x_true) {
  auto gz = torch::matmul(h, x_true);
  auto z = gz.clone();
  return z;
}

void extended_prediction(torch::Tensor& x, torch::Tensor& p, double dt) {

  auto d1 = x.index({3}) / x.index({4});
  auto d2 = dt * d1;
  auto d3 = x.index({3}) / x.index({4}).square();
  auto d4 = (1.0 / x.index({4}));


  auto s1 = torch::sin(x.index({4}) * dt + x.index({2}));
  auto c1 = torch::cos(x.index({4}) * dt + x.index({2}));
  auto s2 = torch::sin(x.index({2}));
  auto c2 = torch::cos(x.index({2}));

  x.index_put_({0}, x.index({0}) + d1 * (s1 - s2));
  x.index_put_({1}, x.index({1}) + d1 * (-c1 + c2));
  x.index_put_({2}, x.index({2}) + x.index({4}) * dt);
  x.index_put_({3}, x.index({3}));
  x.index_put_({4}, torch::tensor(std::min(x.index({4}).item<double>(), 0.5), tensor_options_.dtype(torch::kFloat32)));

  auto a13 = d1 * (c1 -c2);
  auto a14 = d4 * (s1 - s2);
  auto a15 = d2 * c1 - d3 * (s1 - s2);
  auto a23 = d1 * (s1 - s2);
  auto a24 = d4 * (-c1 + c2);
  auto a25 = d2 * s1 - d3 * (-c1 + c2);

  auto jF = torch::tensor({{1.0, 0.0, 0.0, 0.0, 0.0},
                           {0.0, 1.0, 0.0, 0.0, 0.0},
                           {0.0, 0.0, 1.0, 0.0, 0.0},
                           {0.0, 0.0, 0.0, 1.0, 0.0},
                           {0.0, 0.0, 0.0, 0.0, 1.0}}, tensor_options_.dtype(torch::kFloat32));

  jF.index_put_({0, 2}, a13);
  jF.index_put_({0, 3}, a14);
  jF.index_put_({0, 4}, a15);
  jF.index_put_({1, 2}, a23);
  jF.index_put_({1, 3}, a24);
  jF.index_put_({1, 4}, a25);
  jF.index_put_({2, 4}, dt);

  p = torch::matmul(torch::matmul(jF, p), jF.transpose(0, 1)) + q;

}

void linear_update(torch::Tensor& x_pred, 
                   torch::Tensor& p_pred, 
                   const torch::Tensor& z) {
  auto s = torch::matmul(torch::matmul(h, p_pred), h.transpose(0, 1)) + r;
  auto k = torch::matmul(torch::matmul(p_pred, h.transpose(0, 1)), torch::inverse(s));
  auto v = z - torch::matmul(h, x_pred);
  x_pred = x_pred + torch::matmul(k, v);
  p_pred = p_pred - torch::matmul(torch::matmul(k, s), k.transpose(0, 1));
}

int main() {

  auto x_0 = torch::tensor({{0.0},
                            {0.0},
                            {0.0},
                            {1.0},
                            {0.01}});


  auto p_0 = torch::tensor({{0.1, 0.0, 0.0, 0.0, 0.0},
                            {0.0, 0.1, 0.0, 0.0, 0.0},
                            {0.0, 0.0, 0.1, 0.0, 0.0},
                            {0.0, 0.0, 0.0, 0.1, 0.0},
                            {0.0, 0.0, 0.0, 0.0, 0.1}});

  auto x_est = x_0.clone();
  auto p_est = p_0.clone();
  auto x_true = x_0.clone();
  auto p_true = p_0.clone();

  std::vector<torch::Tensor> save;

  double dt = 0.1;

  for (int i = 0; i < 20; ++i) {
    // 模拟更新
    extended_prediction(x_true, p_true, dt);

    // 观测
    auto z = gen_measurement(x_true);

    // 加权
    extended_prediction(x_est, p_est, dt);
    linear_update(x_est, p_est, z);

    save.push_back(x_est.index({Slice(None), Slice(0, 2)}));

    std::cout  << x_est.index({Slice(None), Slice(0, 2)}) << std::endl;
  }

  // std::cout  << save << std::endl;

}