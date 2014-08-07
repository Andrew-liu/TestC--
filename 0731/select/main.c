#include "select_t.h"
#include "network.h"
#include <sys/types.h>
#include <sys/socket.h>

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
    printf("OK\n");
    select_t sel;
    select_init(&sel, listenfd, handle);
    while(1)
    {
        select_do_wait(&sel);
        select_handle_accept(&sel);
        select_handle_data(&sel);
    }
    close(listenfd);
    return 0;
}
