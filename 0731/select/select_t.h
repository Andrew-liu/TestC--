#ifndef _SELECT_T_
#define _SELECT_T_

#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/select.h>


#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

typedef struct
{
    fd_set allset;
    fd_set rset;
    int client[FD_SETSIZE];
    int maxi;//减少轮询次数
    int maxfd;
    int listenfd;
    int readn;
    void (*handle_callback)(int, char *);
}select_t;


int make_socket();
void select_init(select_t *sel, int listenfd, void (*handle)(int, char *));
int select_do_wait(select_t *sel);
void select_handle_accept(select_t *sel);
void select_handle_data(select_t *sel);

#endif
