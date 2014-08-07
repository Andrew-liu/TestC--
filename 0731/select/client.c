#include "network.h"
#include <poll.h>

/*
void do_service(int peerfd)
{
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};

    
    //准备工作，主要是一些参数
    struct pollfd client[2];  //这里监听两个fd
    client[0].fd = fileno(stdin);
    client[0].events = POLLIN;  //表示监听读事件
    client[1].fd = peerfd;
    client[1].events = POLLIN;
    int maxi = 1;  //代表数组的最大下标
    int nready;  //接收poll的返回值

    while(1)
    {
        //int poll(struct pollfd *fds, nfds_t nfds, int timeout);
        nready = poll(client, maxi + 1, -1);  //-1表示永久等待
        if(nready == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("poll");
        }else if(nready == 0)
            continue;
        
        //依次检查stdin和peerfd
        if(client[0].revents & POLLIN)  //client[0]的返回状态中含有POLLIN
        {
            if(fgets(sendbuf, 1024, stdin) == NULL)
            {
                shutdown(peerfd, SHUT_WR);
                client[0].fd = -1;  //不再监听stdin
            }else{
                writen(peerfd, sendbuf, strlen(sendbuf));
            }
        }

        if(client[1].revents & POLLIN)
        {
            int ret = readline(peerfd, recvbuf, 1024);
            if(ret == -1)
                ERR_EXIT("readline");
            else if(ret == 0)
            {
                printf("server close\n");
                close(peerfd);
                break;
            }
            printf("recv data: %s", recvbuf);
        }

    }

}
*/
void do_service(int peerfd)
{

    char inbuf[1024] = {0};
    char recvbuf[1024] = {0};
    struct pollfd client[2];
    client[0].fd = fileno(stdin);
    client[0].events = POLLIN;
    client[1].fd = peerfd;
    client[1].events = POLLIN;
    int maxi = 2;
    int ret;
    while(1)
    {
        ret = poll(client, maxi, -1);
        if(ret == -1)
        {
            if(errno == EINTR)
            {
                continue;
            }
            ERR_EXIT("poll");
        }
        else if(ret == 0)
        {
            continue;
        }

        if(client[0].revents & POLLIN)
        {
            if(fgets(inbuf, 1024, stdin) == NULL)
            {
                shutdown(client[0].fd, SHUT_WR);
                client[0].fd = -1;
            }
            else
            {
                write(peerfd, inbuf, strlen(inbuf));
            }
        }
        if(client[1].revents & POLLIN)
        {
            int readn;
            if((readn = readline(peerfd, recvbuf, 1024)) == -1)
            {
                ERR_EXIT("readline");
            }
            else if(readn == -1)
            {
                printf("server is shutdonw!\n");
                close(peerfd);
                break;
            }
            else
            {
                printf("recv data : %s\n",recvbuf);
            }
        }
        
    }
    
}



int main(int argc, const char *argv[])
{
    //创建socket
    int peerfd = socket(PF_INET, SOCK_STREAM, 1);
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












