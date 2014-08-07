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
    close(STDIN_FILENO);
    //执行完这一行， 0 和 3都指向打开test.txt的文件表项
    dup(fd);


    char buf[1000];
    fgets(buf, 1000, stdin);

    fputs(buf, stdout);

    close(fd);
    return 0;
}
