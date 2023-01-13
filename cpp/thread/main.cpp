#include <iostream>
#include <thread>

static const int nt=10;

void Hello(int num)
{
    std::cout << num << ": Hello thread!" << std::endl;
}

int main(void)
{
    std::thread t[nt];
    
    for (int i=0; i<nt; i++) {
        t[i] = std::thread(Hello, i);
        t[i].detach();
    }

    std::cout << "Main thread exit." << std::endl;
    
    return 0;
}

// 定期重启失败的线程？
// atomic