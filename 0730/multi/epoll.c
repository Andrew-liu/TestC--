#include "network.h"
#include <sys/epoll.h>
#include <sys/select.h>
#include <poll.h>

int get_listen_fd();
void do_epoll(int listenfd);

int main(int argc, const char *argv[])
{
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
        ERR_EXIT("signal");
    
    int listenfd = get_listen_fd();


    do_epoll(listenfd);

    close(listenfd);
    return 0;
}



int get_listen_fd()
{
    //创建socket
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




void do_epoll(int listenfd)
{
    int epollfd = epoll_create(2048);
    if(epollfd == -1)
    {
        ERR_EXIT("epoll_create");
    }
    struct epoll_event ev; //定义一个结构体 放入epollfd
    ev.data.fd = listenfd;
    ev.events = EPOLLIN;
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev) == -1)
        ERR_EXIT("add");
    struct epoll_event client[2048];
    int readn; //保存epoll返回值

    while(1)
    {
        readn = epoll_wait(epollfd, client, 2048, -1);
        if(readn == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("wait");
        }

        int i;
        for(i = 0; i < readn; ++i)
        {
            
            if(client[i].data.fd == listenfd)
            {
                int peerfd = accept(listenfd, NULL, NULL);
                if(peerfd == -1)
                    ERR_EXIT("accept");
                //加入监听列表
                struct epoll_event event;
                event.data.fd = peerfd;
                event.events = EPOLLIN;
                if(epoll_ctl(epollfd, EPOLL_CTL_ADD, peerfd, &event) == -1)
                    ERR_EXIT("ctl add");
            }
            else
            {//不是服务器的fd,为客户端的fd有动态时
                int clientfd = client[i].data.fd;
                char buf[1024] = {0};
                int ret = readline(clientfd, buf, 1024);
                if(ret == -1)
                {
                    ERR_EXIT("readline");
                }
                else if(ret == 0)//客户端关闭,
                {
                    printf("client close\n");
                    //从监听中删除
                    struct epoll_event ev1;
                    ev1.data.fd = clientfd;
                    if(epoll_ctl(epollfd, EPOLL_CTL_DEL, clientfd, &ev1) == -1)
                    ERR_EXIT("DEL");
                    close(clientfd);
                    continue;
                }
                printf("recv data :%s",buf);
                writen(clientfd, buf, strlen(buf));
            }
 
            
        }
    }
    close(epollfd);
}
