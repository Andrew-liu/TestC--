#include "epoll_t.h"
#include <errno.h>

void epoll_add_fd(epoll_t *epoll, int peerfd);
void epoll_del_fd(epoll_t *epoll, int peerfd);

int make_socket()
{
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        ERR_EXIT("socket");


    //设置端口复用
    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt");

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8989);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //bind端口
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof servaddr) < 0)
        ERR_EXIT("bind");

    //listen端口
    if(listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("listen");

    return listenfd;
}

void epoll_init(epoll_t *epoll,
                int listenfd, 
                void (*handle)(int, char *))
{
    int epollfd;
    if((epollfd = epoll_create(2048)) == -1)
        ERR_EXIT("create");
    epoll->epollfd = epollfd;
    epoll->listenfd =listenfd;
    epoll_add_fd(epoll, listenfd);
    epoll->nread = 0;
    epoll->handle_callback = handle;
}

void epoll_do_wait(epoll_t *epoll)
{
    int nread;
    do
    {
        nread = epoll_wait(epoll->epollfd, epoll->client, 2048, -1);
    }while(nread == -1 && errno == EINTR);
    if(nread == -1)
    {
        ERR_EXIT("wait");
    }
    epoll->nread = nread;
}

void epoll_handle(epoll_t *epoll)
{
    int i;
    for(i = 0; i < epoll->nread; ++i)//注意整个循环
    {
        int fd = epoll->client[i].data.fd;
        if(fd == epoll->listenfd)
        {
            epoll_handle_accept(epoll);
        }
        else
        {
            epoll_handle_data(epoll, fd);
        }
    }
}

void epoll_handle_accept(epoll_t *epoll)
{
    int peerfd = accept(epoll->listenfd, NULL, NULL);
    if(peerfd == -1)
        ERR_EXIT("accept");
    epoll_add_fd(epoll, peerfd); //注册描述符
}

void epoll_add_fd(epoll_t *epoll, int peerfd)
{
    struct epoll_event ev;
    ev.data.fd = peerfd;
    ev.events = EPOLLIN;
    if(epoll_ctl(epoll->epollfd, EPOLL_CTL_ADD, peerfd, &ev) != 0)
        ERR_EXIT("ADD");
}

void epoll_handle_data(epoll_t *epoll, int peerfd)
{
    char buf[1024];
    int ret = readline(peerfd, buf, 1024);
    if(ret == -1)
    {
        ERR_EXIT("readline");
    }
    else if(ret == 0)
    {
        printf("client close\n");
        epoll_del_fd(epoll, peerfd);
        return ;//这个立即返回
    }
    epoll->handle_callback(peerfd, buf);
}

void epoll_del_fd(epoll_t *epoll, int peerfd)
{
    struct epoll_event ev;
    ev.data.fd = peerfd;
    if(epoll_ctl(epoll->epollfd, EPOLL_CTL_DEL,peerfd, &ev) != 0)//注意对于函数epoll_ctl成功返回的值为0
        ERR_EXIT("DEL");
}

void epoll_close(epoll_t *epoll)
{
    close(epoll->listenfd);
    close(epoll->epollfd);
}
