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

    int fd2 = fcntl(fd, F_DUPFD, 0);
    if(fd2 == -1)
        ERR_EXIT("fcntl");

    /*
    char buf[100];
    fgets(buf, 100, stdin);
    fputs(buf, stdout);
*/

    char buf[1000] = {0};
    read(fd2, buf, 1000);
    fputs(buf, stdout);

    close(fd);
    close(fd2);

    return 0;


}
