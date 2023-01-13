//  Hello World client

#include <assert.h>
#include <unistd.h>
#include <zmq.h>

#include <iostream>
// #include <string>

#include "test.pb.h"

using namespace std;

int main(void) {
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    int rc = zmq_connect(subscriber, "tcp://10.10.18.85:7766");
    rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, NULL, 0);
    assert(rc == 0);

    while (1) {
        zmq_msg_t message;
        zmq_msg_init(&message);
        zmq_msg_init_size(&message, sizeof(zmq_msg_t));

        int nSize = zmq_recvmsg(subscriber, &message, 0);
        std::cout << std::endl;

        char *pData = new char[nSize];
        memcpy(pData, zmq_msg_data(&message), nSize);
        delete [] pData;

        Response proto;
        proto.ParseFromString(pData);
        std::cout << "nSize " << nSize                 //
                  << ", door " << proto.door_opened()  //
                  << ", status " << proto.status()     //
                  << std::endl;

        zmq_msg_close(&message);
    }
    zmq_close(subscriber);
    zmq_term(context);

    system("pause");

    return 0;
}