#ifndef _EPOLL_T_
#define _EPOLL_T_

#include "Sever.h"
#include <iostream>
#include <functional>
#include <sys/epoll.h>
#include <string.h>

class Epoll_t : public Sever
{
    public:
        typedef std::function< void (int, char *)> EpollCallback;
        Epoll_t(EpollCallback callback);
        ~Epoll_t();
        
        void wait();
        void handle();
        void handle_accept();
        void handle_data(int fd);

    private:
        void add_fd(int peerfd);
        void del_fd(int fd);
        int epollfd_;
        struct epoll_event client_[2048];
        int readn_;
        EpollCallback callback_;

};
#endif
