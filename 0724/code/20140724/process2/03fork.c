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

    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd == -1)
        ERR_EXIT("open");

    else if(pid > 0)
    {
        //子进程先执行
        sleep(10);
        write(fd, "hello", strlen("hello"));
        sleep(3);
        close(fd);
    }else
    {
        write(fd, "world", strlen("world"));
        close(fd);
    }
    return 0;
}






