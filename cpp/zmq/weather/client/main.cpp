//  Weather update client
//  Connects SUB socket to tcp://localhost:5556
//  Collects weather updates and finds avg temp in zipcode
#include <assert.h>
#include <zmq.h>

#include "zhelpers.h"

int main(int argc, char *argv[]) {
    //  Socket to talk to server
    printf("Collecting updates from weather server...\n");
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    int rc = zmq_connect(subscriber, "tcp://10.10.18.85:7766");
    assert(rc == 0);

    // 必须调用，否则屏蔽所有消息；
    // 不为空时，过滤满足该前缀的消息；
    // 为空时，接收所有消息。
    rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, NULL, 0);
    assert(rc == 0);

    while (1) {
        char *string = s_recv(subscriber);
        printf("subscriibe : %s\n", string);
        free(string);
    }

    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    return 0;
}