#include "select_t.h"
#include <assert.h>


void select_add_fd(select_t *sel, int peerfd); //防止用户调用,对用户不可见
void select_del_fd(select_t *sel, int i);

int make_socket()
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
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

void select_init(select_t *sel, int listenfd, void (*handle)(int, char *))
{
    FD_ZERO(&sel->allset);
    FD_ZERO(&sel->rset);
    sel->listenfd = listenfd;
    FD_SET(listenfd, &sel->allset);
    sel->maxi = -1;
    sel->maxfd = listenfd;
    int i;
    for(i = 0; i < FD_SETSIZE; ++i)
    {
        sel->client[i] = -1;
    }
    printf("init ok\n");
    sel->handle_callback = handle;
}   

int select_do_wait(select_t *sel)
{
    int readn;
    sel->rset = sel->allset;
    do
    {
        readn = select(sel->maxfd + 1, &sel->rset, NULL, NULL, NULL);
    }while(readn == -1 && errno ==EINTR);
    if(readn == -1)//非中断情况下出错退出
    {
        ERR_EXIT("select");
    }
    sel->readn = readn;
    return readn;
}

void select_handle_accept(select_t *sel)
{
    if(FD_ISSET(sel->listenfd, &sel->rset))
    {
        int peerfd = accept(sel->listenfd, NULL, NULL);
        if(peerfd == -1)
        {
            ERR_EXIT("accpet");
        }
        select_add_fd(sel, peerfd);
    }
}

void select_add_fd(select_t *sel, int peerfd)
{
    int i;
    for(i = 0; i < FD_SETSIZE; ++i)
    {
        if(sel->client[i] == -1)
        {
            sel->client[i] = peerfd;
            if(i > sel->maxi)
                sel->maxi = i;
            break;
        }
    }
    if(i == FD_SETSIZE)
    {
        fprintf(stderr, "too many client\n");
        exit(EXIT_FAILURE);
    }
    FD_SET(peerfd, &sel->allset);
    if(peerfd > sel->maxfd)
    {
        sel->maxfd = peerfd;
    }
}

void select_handle_data(select_t *sel)
{
    if(sel->readn == 0)
    {  
        return ;
    }
    int i;
    for(i = 0; i < sel->maxi; ++i)
    {
        printf("bu ok");
        int peerfd = sel->client[i];
        if(peerfd == -1)
            continue;
        if(FD_ISSET(sel->client[i], &sel->rset))
        {
            printf("ok");
            char buf[1024];
            int ret = readline(peerfd, buf, 1024);
            if(ret == -1)
            {
                ERR_EXIT("readline");
            }
            else if(ret == 0)
            {
                printf("client close\n");
                select_del_fd(sel, i);
                continue;
            }
            printf("%s", buf);
            sel->handle_callback(peerfd, buf);
        }
    }
}

void select_del_fd(select_t *sel, int i)
{
    assert(i >= 0 && i < FD_SETSIZE);
    int peerfd = sel->client[i];
    sel->client[i] = -1;
    FD_CLR(peerfd, &sel->allset);
    close(peerfd);
}


