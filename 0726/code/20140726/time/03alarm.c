#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void handler(int signum)
{
    printf("recvive a msg\n");
    alarm(1);
}


int main(int argc, const char *argv[])
{
    if(signal(SIGALRM, handler) == SIG_ERR)
        ERR_EXIT("signal");

    //3秒后发一个信号
    alarm(3);


    for(;;)
        pause();

    return 0;
}
