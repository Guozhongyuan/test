//  Hello World client

#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <zmq.h>

#include <iostream>
#include <string>

#include "test.pb.h"

using namespace std;

int main(void) {
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    assert(nullptr != publisher);

    int rc = zmq_bind(publisher, "tcp://10.10.18.85:7766");
    assert(rc == 0);

    for (int i = 0; i < 100; ++i) {
        sleep(1);
        clock_t start, end;
        start = clock();

        Response proto;
        proto.set_status(Response::PROCESS_POWEROFF);
        proto.set_fail_reson(Response::AUTO_MODE);
        proto.set_door_opened(1);
        std::string sData = proto.SerializePartialAsString();  //部分序列化
        proto.Clear();                                         // 清空内容

        zmq_msg_t message;
        zmq_msg_init_size(&message, sData.length());
        memcpy(zmq_msg_data(&message), sData.c_str(), sData.length());

        // TODO: 是否需要把长度输入进去，当做校验位？
        // size_t intType = zmq_msg_size(&message);
        // printf("zmq_msg_size: %d\n", intType);

        zmq_msg_send(&message, publisher, 0);
        zmq_msg_close(&message);

        // Response res;
        // res.ParseFromString(sData);5
        // std::cout << res.door_opened() << std::endl;

        end = clock();
        double time = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "sending " << sData.data()  //
                  << ", time " << time           //
                  << std::endl;
    }
    zmq_close(publisher);
    zmq_ctx_destroy(context);

    return 0;
}