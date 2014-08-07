#ifndef _POLL_T_
#define _POLL_T_

#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <poll.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

typedef struct
{
    struct pollfd client[2048];
    int maxi;
    int nready;
    int listenfd;
    void (*handle_callback) (int, char*);
}poll_t;

int make_socket();
void poll_init(poll_t *pol, int listenfd, void (*handle)(int, char *));
void poll_do_wait(poll_t *pol);
void poll_handle_accept(poll_t *pol);
void poll_handle_data(poll_t *pol);

#endif
