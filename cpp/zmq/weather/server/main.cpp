//  Weather update server
//  Binds PUB socket to tcp://*:5556
//  Publishes random weather updates

#include <assert.h>
#include <time.h>
#include <zmq.h>

#include <iostream>

#include "unistd.h"
// #include "zhelpers.h"

int main(void) {
    struct timespec cur_time = {0, 0};

    //  Prepare our context and publisher
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    int rc = zmq_bind(publisher, "tcp://10.10.18.85:7766");
    assert(rc == 0);
    while (1) {
        //  Send message to all subscribers
        sleep(1);
        clock_gettime(CLOCK_REALTIME, &cur_time);
        char update[20] = "hello";
        std::cout << cur_time.tv_sec << " " << cur_time.tv_nsec << " " << update << std::endl;
        s_send(publisher, update);
    }
    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}