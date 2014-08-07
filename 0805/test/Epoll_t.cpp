#include "Epoll_t.h"

Epoll_t::Epoll_t(EpollCallback callback)
    :callback_(callback)
{
   epollfd_ = epoll_create(2048);
   if(epollfd_ == -1)
   {
        ERR_EXIT("epoll_create");
   }
   readn_ = 0;
   add_fd(listenfd_);
}

Epoll_t::~Epoll_t()
{
    close(epollfd_);
    close(listenfd_);
}

void Epoll_t::wait()
{
    int ret;
    do
    {
        ret = epoll_wait(epollfd_, client_, 2048, -1);
    }while(ret == -1 && errno == EINTR);
    if(ret == -1)
    {
        ERR_EXIT("epoll_wait");
    }
    readn_ = ret;
}

void Epoll_t::handle()
{
    for(int i = 0; i < readn_; ++i)
    {
        int fd = client_[i].data.fd;
        if(fd == listenfd_)
        {
            handle_accept();
        }
        else
        {
            handle_data(fd);
        }
    }
}

void Epoll_t::handle_accept()
{
    int peerfd = accept(listenfd_, NULL, NULL);
    if(peerfd == -1)
    {
        ERR_EXIT("accept");
    }
    add_fd(peerfd);
}

void Epoll_t::add_fd(int peerfd)
{
    struct epoll_event ev;
    memset(&ev, 0, sizeof(ev));
    ev.data.fd = peerfd;
    ev.events = EPOLLIN;
    if(epoll_ctl(epollfd_, EPOLL_CTL_ADD, peerfd, &ev) == -1)
    {
        ERR_EXIT("epoll_ctl_add");
    }
}

void Epoll_t::handle_data(int fd)
{
    char buf[1024] = {0};
    int ret = readline(fd, buf, 1024);
    if(ret == -1)
    {
        ERR_EXIT("readline");
    }
    else if(ret == 0)
    {
        std::cout << "client close" << std::endl;
        del_fd(fd);
        return ;
    }
    printf("%s\n", buf);
    callback_(fd, buf);
}

void Epoll_t::del_fd(int fd)
{
    struct epoll_event ev;
    memset(&ev, 0, sizeof(ev));
    ev.data.fd = fd;
    if(epoll_ctl(epollfd_, EPOLL_CTL_DEL, fd, &ev) == -1)
    {
        ERR_EXIT("epoll_ctl_del");
    }
}
