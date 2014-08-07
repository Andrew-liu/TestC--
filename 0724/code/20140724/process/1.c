#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    //获取进程ID
    printf("pid = %d\n", getpid());
    //获取父进程的ID
    printf("ppid = %d\n", getppid());
    return 0;
}
