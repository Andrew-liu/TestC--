#include "epoll.h"

event *event_init(handle_callback callback, int size)
{
    struct event *ev;
    int epfd = epoll_create(size);
    if(epfd == -1)
        ERR_EXIT("epoll_create");
    ev = (struct event *)malloc(sizeof(struct event));
    if(!ev)
    {
        return NULL;
    }
    ev->callback = callback;
    ev->nevents = size;
    ev->epfd = epfd;
    ev->events = (struct epoll_event *)malloc(size * sizeof(struct epoll_event));
    if(!ev->events)
    {
        free(ev);
        return NULL
    }
    return ev;
}

int event_destroy(event *handle)
{
    if(handle)
    {
        if(handle->epfd > 0)
        {
            close(handle->epfd);
        }
        if(handle->events)
        {
            free(handle->events);
        }
        free(handle);
    }
    return 1;
}

int event_add(event *handle, int fd, int op)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLOUT;
    if(op & EPOLLIN)
    {
        event.events &= EPOLLIN;
    }
    if(op & EPOLLIN)
    {
        event.events &= EPOLLOUT;
    }
    if(epoll_ctl(handle->epfd, EPOLL_CTL_ADD, fd, &event) < 0)
    {
        ERR_EXIT("ctl_add");
    }
    return 1;

}

int event_del(event *handle, int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    if(epoll_ctl(handle->epfd, EPOLL_CTL_DEL, fd, &event) < 0)
    {
        ERR_EXIT("ctl_del");
    }
    return 1;
}
