#include "network.h"
#include "poll_t.h"
#include <signal.h>
void handle(int fd, char *buf)
{
    printf("recv data : %s", buf);
    writen(fd, buf, strlen(buf));
}

int main(int argc, const char *argv[])
{
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
        ERR_EXIT("signal");

    int listenfd = make_socket();
    printf("listen %d\n",listenfd);

    poll_t pol;
    poll_init(&pol, listenfd, handle);
    while(1)
    {
        poll_do_wait(&pol);
        poll_handle_accept(&pol);
        poll_handle_data(&pol);
    }
    close(listenfd);
    return 0;
}
