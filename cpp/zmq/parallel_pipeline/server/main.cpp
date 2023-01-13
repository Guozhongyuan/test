//  Hello World server
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>
#include <iostream>

int main(void) {
    //  Socket to talk to clients
    void *context = zmq_ctx_new();
    void *responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://*:5555");
    assert(rc == 0);

    while (1) {
        char buffer[10];
        // TODO: send json ?
        zmq_recv(responder, buffer, 10, 0);
        // printf("Received Hello\n");
        std::cout << buffer << std::endl;
        sleep(1);
        zmq_send(responder, "World", 5, 0);
    }
    return 0;
}