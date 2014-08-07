#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_RDONLY, 0666);
    if(fd == -1)
        ERR_EXIT("open");

    // stdin -> test.txt

    //首先关闭STDIN_FILENO，然后将该fd指向test.txt的文件表项
    dup2(fd, STDIN_FILENO);

    char buf[1000];
    fgets(buf, 1000, stdin);

    fputs(buf, stdout);

    close(fd);
    return 0;
}
