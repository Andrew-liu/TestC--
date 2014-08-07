#include "Select_t.h"

Select_t::Select_t(SelectCallback callback)
    :callback_(callback)
{
    FD_ZERO(&allset_);
    FD_ZERO(&rset_);
    FD_SET(listenfd_, &allset_);
    maxi_ = -1;
    maxfd_ = listenfd_;
    for(int i =0; i < FD_SETSIZE; ++i)
    {
        client_[i] = -1;
    }
    readn_ = 0; 
}

Select_t::~Select_t()
{
    close(listenfd_);
}

void Select_t::wait()
{   
    int ret;
    rset_ = allset_;
    do
    {
        ret = select(maxfd_ + 1, &rset_, NULL, NULL, NULL);
    }while(ret == -1 && errno ==EINTR);
    if(ret == -1)
    {
        ERR_EXIT("select");
    }
    readn_ = ret;
    printf("select\n");
}

void Select_t::handle_accept()
{
    if(FD_ISSET(listenfd_, &rset_))
    {
        printf("listen\n");
       int peerfd = accept(listenfd_, NULL, NULL);
       if(peerfd == -1)
       {
        ERR_EXIT("accept");
       }
       add_fd(peerfd);
    }
}

void Select_t::add_fd(int peerfd)
{
    int i;
    for(i = 0; i < FD_SETSIZE; ++i)
    {
        printf("add\n");
        if(client_[i] == -1)
        {
            client_[i] = peerfd;
            if(i > maxi_)
            {
                maxi_ = i;
            }
            break;
        }
    }
    if(i == FD_SETSIZE)
    {
        fprintf(stderr, "too many client");
        exit(EXIT_FAILURE);
    }
    FD_SET(peerfd, &allset_);
    if(peerfd > maxfd_)
    {
        maxfd_ = peerfd;
    }
}

void Select_t::handle_data()
{
    for(int i =0; i <= maxi_; ++i)
    {
        printf("data\n");
        int peerfd = client_[i];
        if(peerfd == -1)
            continue;
        if(FD_ISSET(peerfd, &rset_))
        {
            char buf[1024] = {0};
            int ret = readline(peerfd, buf, 1024);
            if(ret == -1)
                ERR_EXIT("readline");
            else if(ret == 0)
            {//关闭描述符从集合中删除
                std::cout << "client close" << std::endl;
                del_fd(i);
                continue;
            }
            printf("%s\n", buf);
            callback_(peerfd, buf);
        }
    }

}

void Select_t::del_fd(int i)
{
    int peerfd = client_[i];
    client_[i] = -1;
    FD_CLR(peerfd, &allset_);
    close(peerfd);
}
