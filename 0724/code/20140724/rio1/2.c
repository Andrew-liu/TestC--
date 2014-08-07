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

/*
 * 效率低下
 * 参数指定为maxlen，但是最多读取mexlen-1
 * 最后一个位置留给\0
 *
 * maxlen足够大的情况下，buf的最终内容为
 * XXXXXX \n\0
 */
ssize_t readline(int fd, void *usrbuf, size_t maxlen)
{
    char *bufp = usrbuf;  //记录缓冲区当前位置
    ssize_t nread;
    size_t nleft = maxlen - 1;  //留一个位置给 '\0'
    char c;
    while(nleft > 0)
    {
        if((nread = read(fd, &c, 1)) < 0)
        {
            if(errno == EINTR)
                continue;
            return -1;
        }else if(nread == 0) // EOF
        {
            break;
        }

        //普通字符
        *bufp++ = c;
        nleft--;

        if(c == '\n')
            break;
    }
    *bufp = '\0';
    return (maxlen - nleft - 1);
}


int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_RDONLY, 0666);
    if(fd == -1)
        ERR_EXIT("open");
    int ret;
    char buf[1024];
    while((ret = readline(fd, buf, 1024)))
    {
        printf("ret= %d, buf = %s\n", ret, buf);
    }
    return 0;
}








