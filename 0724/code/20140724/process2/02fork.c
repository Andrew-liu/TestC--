#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


int main(int argc, const char *argv[])
{
    pid_t pid = fork();    
    if(pid == -1)
        ERR_EXIT("fork");

    int fd = open("test.txt", O_RDONLY);
    if(fd == -1)
        ERR_EXIT("open");

    else if(pid > 0)
    {
        //子进程先执行
        sleep(3);
        char buf[100] = {0};
        read(fd, buf, 3);
        printf("In parent  buf = %s\n", buf);
        sleep(3);
    }else
    {
        char buf[100] = {0};
        read(fd, buf, 3);
        printf("In Child  buf = %s\n", buf);
    }
    return 0;
}






