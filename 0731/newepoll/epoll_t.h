#ifndef _EPOLL_T_
#define _EPOLL_T_

#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

typedef struct
{
    int epollfd;
    int listenfd;
    struct epoll_event client[2048];
    int nread;
    void (*handle_callback)(int, char *);
}epoll_t;

int make_socket();
void epoll_init(epoll_t *epoll, int listenfd, void (*handle)(int, char *));
void epoll_do_wait(epoll_t *epoll);
void epoll_handle(epoll_t *epoll);
void epoll_handle_accept(epoll_t *epoll);
void epoll_handle_data(epoll_t *epoll, int peerfd);
void epoll_close(epoll_t *epoll);

#endif
