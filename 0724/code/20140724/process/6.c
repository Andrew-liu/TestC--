#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

/*
 * 演示孤儿进程
 *
 */
int main(int argc, const char *argv[])
{
    pid_t pid;
    pid = fork();
    if(pid == -1)
        ERR_EXIT("fork");
    else if(pid > 0)
    {
        //父进程
        printf("In Parent, pid = %d, child = %d\n", getpid(), pid);
        exit(EXIT_SUCCESS);
    }else
    {
        sleep(1);
        //子进程
        printf("In Child, pid = %d, parent = %d\n", getpid(), getppid());
        sleep(20);
    }

    return 0;
}





