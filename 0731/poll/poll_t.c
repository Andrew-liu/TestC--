#include "poll_t.h"
#include <errno.h>
#include <assert.h>
void poll_add_fd(poll_t *pol, int peerfd);
void poll_del_fd(poll_t *pol, int i);

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


void poll_init(poll_t *pol, 
        int listenfd,
        void (*handle)(int, char *))
{
    int i;
    for(i = 0; i < 2048; ++i)
    {
        pol->client[i].fd = -1;
    }
    pol->client[0].fd = listenfd;
    pol->client[0].events = POLLIN;
    pol->listenfd = listenfd;
    pol->maxi = 0;
    pol->handle_callback = handle;
    pol->nready = 0;
//    printf("init\n");
}

void poll_do_wait(poll_t *pol)
{
    int nready;
    do
    {
        nready = poll(pol->client, pol->maxi + 1, -1);
    }while(nready == -1 && errno == EINTR);
    if(nready == -1)
        ERR_EXIT("Poll");
    pol->nready = nready;
  //  printf("poll\n");
}

void poll_handle_accept(poll_t *pol)
{
   // printf("acc\n");
    if(pol->client[0].revents & POLLIN)
    {
        int peerfd = accept(pol->listenfd, NULL, NULL);
     //   printf("peerfd, %d\n",peerfd);
        if(peerfd == -1)
        {
            ERR_EXIT("accept");
        }
        poll_add_fd(pol, peerfd);
    }
}

void poll_add_fd(poll_t *pol, int peerfd)
{
    int i;
  //  printf("add\n");
    for(i = 1; i < 2048; ++i)
    {
        if(pol->client[i].fd == -1)
        {
            pol->client[i].fd = peerfd;
            pol->client[i].events = POLLIN; //这里不要忘记加POLLIN
            if(i > pol->maxi)
            {
                pol->maxi = i;
            }
            break;
        }
    }
    if(i == 2048)
    {
        fprintf(stderr, "too many client\n");
        exit(EXIT_FAILURE);
    }
}

void poll_handle_data(poll_t *pol)
{
    int i;
    char buf[1024];
  //  printf("handle\n");
    for(i = 1; i <= pol->maxi; ++i)//整个循环的条件要注意
    {
        int peerfd = pol->client[i].fd;
        if(peerfd == -1)
            continue;
        if(pol->client[i].revents & POLLIN)
        {
            int ret = readline(peerfd, buf, 1024);
            if(ret == -1)
                ERR_EXIT("readline");
            else if(ret == 0)
            {
                printf("client close\n");
                poll_del_fd(pol, i);
                continue;//要继续下一次循环
            }
            pol->handle_callback(peerfd, buf);
        }
    }
}

void poll_del_fd(poll_t *pol, int i)
{
    assert(i > 0 && i < 2048);
    close(pol->client[i].fd);
    pol->client[i].fd = -1;
}
