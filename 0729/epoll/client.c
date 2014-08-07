#include "network.h"
#include <sys/epoll.h>
/*

void do_service(int peerfd)
{
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};

    //准备工作
    //1.创建epoll句柄，fd
    int epollfd = epoll_create(2);  //创建容纳两个监听描述符的epoll描述符
    if(epollfd == -1)
        ERR_EXIT("epoll_create");
    //2.注册两个fd
    struct epoll_event ev;  //分别将描述符信息放入结构体
    ev.events = EPOLLIN;
    ev.data.fd = STDIN_FILENO;
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev) == -1) //注册监听描述符
        ERR_EXIT("epoll_ctl");
    ev.events = EPOLLIN;
    ev.data.fd = peerfd;
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, peerfd, &ev) == -1)
        ERR_EXIT("epoll_ctl");

    //3.准备一个数组,从内核得到事件的集合
    struct epoll_event events[2];
    int nready;

    while(1)
    {
        //int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout); 
        nready = epoll_wait(epollfd, events, 2, -1);
        if(nready == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("epoll_wait");
        }else if(nready == 0)
            continue;


        //开始检查每个fd 
        int i;
        for(i = 0; i < nready ; ++i)
        {
            int fd = events[i].data.fd;
            if(fd == STDIN_FILENO)
            {
                if(fgets(sendbuf, 1024, stdin) == NULL)
                {
                    shutdown(peerfd, SHUT_WR);
                    //移除stdin这个fd
                    struct epoll_event ev;
                    ev.data.fd = STDIN_FILENO;
                    if(epoll_ctl(epollfd, EPOLL_CTL_DEL, STDIN_FILENO, &ev) == -1)
                        ERR_EXIT("Epoll_ctl");
                }else
                {
                    writen(peerfd, sendbuf, strlen(sendbuf));
                }
            }

            if(fd == peerfd)
            {
                int ret = readline(peerfd, recvbuf, 1024);
                if(ret == -1)
                    ERR_EXIT("readline");
                else if(ret == 0)
                {
                    close(peerfd);
                    printf("server close\n");
                    exit(EXIT_SUCCESS);
                }
                printf("recv data: %s", recvbuf);
            }
            

        }
    }



}
*/

void do_service(int peerfd)
{
    char inbuf[1024] = {0};
    char recvbuf[1024] = {0};

    int epfd = epoll_create(2);
    if(epfd == -1)
    {
        ERR_EXIT("create");
    }
    struct epoll_event ev1;
    ev1.events = EPOLLIN;
    ev1.data.fd = STDIN_FILENO;
    int ret1 = epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev1);
    if(ret1 == -1)
    {
        ERR_EXIT("ctl1 ");
    }
    struct epoll_event ev2;
    ev2.events = EPOLLIN;
    ev2.data.fd = peerfd;
    int ret2 = epoll_ctl(epfd, EPOLL_CTL_ADD, peerfd, &ev2);
    if(ret2 == -1)
    {
        ERR_EXIT("ctl2");
    }

    struct epoll_event ev[2];
    int readn;

    while(1)
    {
        readn = epoll_wait(epfd, ev, 2, -1);
        if(readn == -1)
        {
            if(errno == EINTR)
            {
                continue;
            }
            ERR_EXIT("wait");
        }
        else if(read == 0)
        {
            continue;
        }
        //监听每个描述符
        int i;
        for(i = 0; i < readn; ++i)
        {
            int fd = ev[i].data.fd;
            if(fd == STDIN_FILENO)
            {
                if(fgets(inbuf, 1024, stdin) == NULL)
                {
                    shutdown(peerfd, SHUT_WR);
                    struct epoll_event ev3;
                    ev3.data.fd = STDIN_FILENO;
                    epoll_ctl(epfd, EPOLL_CTL_DEL, STDIN_FILENO, &ev3);
                }
                else
                {
                    write(peerfd, inbuf, strlen(inbuf));
                }
            }
            if(fd == peerfd)
            {
                int ret1 = readline(peerfd, recvbuf, 1024);
                if(ret1 == -1)
                {
                    ERR_EXIT("readline");
                }
                else if(ret1 == 0)
                {
                    close(peerfd);
                    printf("sever close");
                    break;
                }
                printf("recv data : %s\n", recvbuf);

            }
        }

    }
    close(epfd);
}


int main(int argc, const char *argv[])
{
    //创建socket
    int peerfd = socket(PF_INET, SOCK_STREAM, 0);
    if(peerfd == -1)
        ERR_EXIT("socket");


    //connect
    struct sockaddr_in peeraddr;
    peeraddr.sin_family = AF_INET;
    peeraddr.sin_port = htons(8989);
    peeraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(peerfd, (struct sockaddr *)&peeraddr, sizeof peeraddr) < 0)
        ERR_EXIT("connect");
    


    do_service(peerfd);


    close(peerfd);

    return 0;
}











