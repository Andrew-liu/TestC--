#include "network.h"

#include <sys/select.h>
#include <poll.h>

int get_listen_fd();
void do_poll(int listenfd);

int main(int argc, const char *argv[])
{
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
        ERR_EXIT("signal");
    
    int listenfd = get_listen_fd();


    do_poll(listenfd);

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




void do_poll(int listenfd)
{
    struct pollfd event[2048];
    event[0].fd = listenfd;
    event[0].events = POLLIN;
    int max = 0;//最大下标
    //对数组进行初始化
    int i ;
    for(i = 1; i < 2048; ++i)
    {
        event[i].fd = -1;
    }
    while(1)
    {
        int readn = poll(event, max + 1, -1);
        if(readn == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("poll");
        }
        else if(readn ==0)
                continue;
        //监听listenfd
        if(event[0].revents & POLLIN)
        {
            int client = accept(listenfd, NULL, NULL);
            if(client == -1)
                ERR_EXIT("accept");
            //放入监听结构体
            int i;
            for(i = 1; i < 2048; ++i)
            {
                if(event[i].fd == -1)
                {
                    event[i].fd = client;
                    event[i].events = POLLIN;
                    max = ((i > max) ? i : max);
                    break;
                }
            }
            if(i == 2048)
            {
                fprintf(stderr, "too many fd\n");
                exit(EXIT_FAILURE);
            }
        }
        //监听已经获取的文件描述符集合
        int i;
        for(i = 1; i <= max; ++i)
        {
            char buf[1024] = {0};
            if(event[i].fd == -1)
                continue;
            if(event[i].revents & POLLIN)
            {
                //此时说明有消息已准备好,接收
                int ret = readline(event[i].fd, buf, 1024);
                if(ret == -1)
                {
                    ERR_EXIT("readline");
                }
                else if(ret == 0)
                {//删除集合的文件描述符
                    close(event[i].fd);
                    event[i].fd = -1;
                    continue;
                }
                printf("recv data : %s",buf);
                writen(event[i].fd, buf,strlen(buf));
            }

            
        }
    
    }

}
