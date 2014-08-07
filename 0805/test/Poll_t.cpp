#include "Poll_t.h"
#include "Sever.h"

Poll_t::Poll_t()
{
    for(int i =0; i < 2048; ++i)
    {
        client_[i].fd = -1;
    }
    client_[0].fd = listenfd_;
    client_[0].events = POLLIN;
    maxi_ = 0;
    readn_ =0;
}

Poll_t::~Poll_t()
{
    close(listenfd_);
}

void Poll_t::setcallback(const HandleCallback &callback)
{
    callback_ = callback;
}

void Poll_t::wait()
{
    int ret; 
    do
    {
        ret = poll(client_, maxi_ + 1, -1);
    }while(ret == -1 && errno == EINTR);
    if(ret == -1)
    {
        ERR_EXIT("wait");
    }
    readn_ = ret;
}

void Poll_t::handle_accept()
{
    if(client_[0].revents & POLLIN)
    {
        int peerfd = accept(listenfd_, NULL, NULL);
        if(peerfd == -1)
        {
            ERR_EXIT("accept");
        }
        add_fd(peerfd);
    }
}

void Poll_t::add_fd(int peerfd)
{
    int i;
    for(i = 1; i < 2048; ++i)
    {
        if(client_[i].fd == -1)
        {
            client_[i].fd = peerfd;
            client_[i].events = POLLIN;
            if(i > maxi_)
            {
                maxi_ = i;
            }
            break;
        }
    }
    if(i == 2048)
    {
        fprintf(stderr, "too many client \n");
        exit(EXIT_FAILURE);
    }
}

void Poll_t::handle_data()
{
    for(int i = 1; i <= maxi_; ++i)
    {
        int peerfd = client_[i].fd;
        if(client_[i].fd == -1)
            continue;
        if(client_[i].revents & POLLIN)
        {
            char buf[1024] = {0};
            int ret = readline(peerfd, buf, 1024);
            if(ret == -1)
            {
                ERR_EXIT("readline");
            }
            else if(ret == 0)
            {
                std::cout << "client close " << std::endl;
                del_fd(i);
                continue;
            }
            printf("%s\n",buf);
            callback_(peerfd, buf);
        } 
    }
}

void Poll_t::del_fd(int i)
{
    client_[i].fd = -1;
    close(client_[i].fd);
}
