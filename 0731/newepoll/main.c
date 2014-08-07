#include "epoll_t.h"
#include "network.h"
#include <signal.h>

void handle(int fd, char *buf)
{
    printf("revc data : %s",buf);
    writen(fd, buf, strlen(buf));
}

int main(int argc, const char *argv[])
{
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)    
        ERR_EXIT("signal");
    int listenfd = make_socket();

    epoll_t epoll;
    epoll_init(&epoll, listenfd, handle);
    while(1)
    {
        epoll_do_wait(&epoll);
        epoll_handle(&epoll);
    }
    epoll_close(&epoll);
    return 0;
}
