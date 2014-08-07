#ifndef _MYEPOLL_
#define _MYEPOLL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

typedef int (*handle_callback)(int fd, int evop);

struct event
{
    handle_callback callback;//回调函数指针
    struct epoll_event *events;//epoll结构体
    int nevents; //描述符的个数
    int epfd; //epoll文件描述符
};

event *event_init(handle_callback, int size);
int event_destroy(event *handle);
int event_add(event *handle, int fd, int op);
int event_del(event *handle, int fd);

#endif
