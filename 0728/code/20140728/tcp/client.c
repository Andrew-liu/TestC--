#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void do_service(int peerfd)
{
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};

    while(1)
    {
        int ret;
        if(fgets(sendbuf, 1000, stdin) != NULL)
        {
            write(peerfd, sendbuf, strlen(sendbuf));
            ret = read(peerfd, recvbuf, 1000);
            if(ret == -1)
            {
                if(errno == EINTR)
                    continue;
                return ;
            }
            else if(ret == 0)
                break;

            printf("receive data: %s", recvbuf);
        }
        
        memset(sendbuf, 0, sizeof sendbuf);
        memset(recvbuf, 0, sizeof recvbuf);
    }

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












