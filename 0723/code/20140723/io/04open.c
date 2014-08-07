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
    //只读
    int fd = open("tes.txt", O_RDONLY);
    if(fd == -1)
        ERR_EXIT("open");
    char buf[1024] = {0};
    read(fd, buf, 1000);
    printf("%s\n", buf);
    
    close(fd);
    return 0;
}

