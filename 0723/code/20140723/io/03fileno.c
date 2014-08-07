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
    //实现从FILE*到fd的转化使用fileno
    int fd = fileno(stdin);
    //STDIN_FILENO
    //

    printf("%d\n", fd);


    return 0;
}
