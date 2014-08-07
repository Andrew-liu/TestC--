#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void handler(int num)
{
    printf("receive!\n");
}

int main(int argc, const char *argv[])
{
    if(signal(SIGALRM, handler) == SIG_ERR)
    {
        ERR_EXIT("signal");        
    }

    struct timeval end;//用于定义时间间隔
    end.tv_sec = 1;
    end.tv_usec = 0;
    struct timeval beg;//用于定义初始时间
    beg.tv_sec = 3;
    beg.tv_usec = 0;

    struct itimerval tm; 
    tm.it_interval = end;//发生信号的间隔
    tm.it_value = beg;//第一次发出信号的初始时间

    setitimer(ITIMER_REAL, &tm, NULL);

    for(; ; )
        pause();
    return 0;
}
