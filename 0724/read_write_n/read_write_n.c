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

ssize_t readn(int fd, char *buf, size_t n)
{
    int nleft = n;
    int nread; //read返回值
    char *bufp = buf;
    while(nleft > 0)
    {
        if((nread = read(fd, bufp, nleft)) == -1)
        {
            if(errno == EINTR)
            {
                nread = 0;
            }
            else
            {
                return -1;
            }
        }
        else if(nread == 0)
        {
            break;  //文件结束才跳出循环
        }
        
        nleft -= nread;
        bufp += nread;
    }
    return (n - nleft);
}
ssize_t writen(int fd, char *buf, size_t n)
{
    int nleft = n;
    int nwrite;
    char *bufp = buf;
    while(nleft > 0)
    {
        if((nwrite = write(fd, bufp, nleft)) <= 0)   
        {
            if(errno == EINTR)
            {
                nwrite = 0;
            }
            else
            {
                return -1;
            }
        }
        nleft -= nwrite;
        bufp +=nwrite;
    }
    return n;
}

int main(int argc, const char *argv[])
{
    int fd = open("1.txt", O_RDONLY);
    int ret;
    char buf[1024];
    memset(buf,0,1024);
    while((ret = readn(fd, buf, 5)) > 0)
    {
        writen(STDOUT_FILENO, buf,ret);
    }
    return 0;
}
