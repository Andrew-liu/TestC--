#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

ssize_t readn(int fd, void *usrbuf, size_t n);
ssize_t writen(int fd, void *usrbuf, size_t n);


/*
 * 除非遇到EOF，否则一定读取n个字节
 * 成功的时候返回读取的字节数
 * 若是字节数小于n，一定是遇到了EOF
 * 如果出错，返回-1
 * 这里的错误一定不包含EINTR
 * 如果一开始就遇到EOF，那么返回0
 */
ssize_t readn(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n; //表示还需要读取的字节数
    ssize_t nread;
    char *bufp = usrbuf; //控制read函数存放的位置

    while(nleft > 0)
    {
        if((nread = read(fd, bufp, nleft)) == -1)
        {
            if(errno == EINTR)  //interupt
                nread = 0;  //continue;  中断需要再次读取
            else
                return -1;  // ERROR
        }else if(nread == 0)  // EOF
            break;
        
        nleft -= nread;
        bufp += nread;
    }
    return (n - nleft);
}

/*
 * 这里的writen必须写满n个字节
 * 少于n就属于错误
 *
 * writen的返回值只有两种
 * n 代表成功
 * -1代表失败
 */
ssize_t writen(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwrite;

    char *bufp = usrbuf;

    while(nleft > 0)
    {
        //nwrite == 0也属于错误
        if((nwrite = write(fd, bufp, nleft)) <= 0)
        {
            if(errno == EINTR)
                nwrite = 0;
            else
                return -1; // -1 和 0
        }

        nleft -= nwrite;
        bufp += nwrite;
    }
    return n;  //这里不是 n- nleft 必须是n
}

int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_RDONLY);
    if(fd == -1)
        ERR_EXIT("open");

    char buf[100] = {0};
    int ret;

    while((ret = readn(fd, buf, 5)) > 0)
    {
        writen(STDOUT_FILENO, buf, ret);
    }

    return 0;
}













