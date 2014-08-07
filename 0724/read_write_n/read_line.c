#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

ssize_t readline(int fd, char *buf, size_t maxlen)
{
    char *bufp = buf;
    ssize_t nread;
    int nleft = maxlen - 1;
    char c;
    while(nleft > 0)
    {
        printf("ok\n");
        if((nread = read(fd, &c, 1)) < 0)
        {
            printf("ok4\n");
            if(errno == EINTR)
            {
               printf("ok2\n");
               continue;
            }
            else
            {
                printf("ok3\n");
                return -1;
            }
        }
        else if(nread == 0)
        {
            break;
        }
        printf("ok5");
        *bufp++ = c;
        nleft--;
        if(c == '\n')
        {
            break;
        }
    }
    *bufp = '\0';

    return (maxlen - nleft - 1);
}
int main(int argc, const char *argv[])
{
    int fd = open("1.txt",O_RDONLY);
    char buf[1024];
    int ret;
    memset(buf, 0, 1024);
    while((ret = readline(fd, buf, 1024)) != -1)
    {
        printf("ret = %d, char = %s \n",ret,buf);
    }
    return 0;
}
