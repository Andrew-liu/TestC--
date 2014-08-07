#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define BUFFERSIZE 8192
#define MAXSIZE 1024
typedef struct rio
{
    int fd_;//描述符
    int left_; //剩余字符数
    char *bufptr_;//表示字符串开头
    char buf_[BUFFERSIZE];
    
}rio_t;

void rio_init(rio_t *rio, int fd)
{
    rio->fd_ =fd;
    rio->left_ = 0;
    rio->bufptr_ = rio->buf_;
}

ssize_t  rio_read(rio_t *rio, char *usrbuf, size_t n)
{
    ssize_t nread;
    //不是每次都进行预读取
    while(rio->left_ <= 0)
    {
        if((nread = read(rio->fd_, rio->buf_, sizeof(rio->buf_)))==-1)
        {
            if(errno == EINTR)
            {
                continue;
            }
            return -1;
        }
        else if(nread == 0)
        {
            return 0; //文件结束
        }
        rio->left_ = nread;
        rio->bufptr_ = rio->buf_;
    }
    
    int cnt = n;
    if(rio->left_ < cnt)
    {
        cnt = rio->left_;
    }
    memcpy(usrbuf, rio->bufptr_, cnt);
    rio->left_ -=cnt;
    rio->bufptr_ += cnt;
    return cnt;
}

ssize_t rio_readn(rio_t *rio, char *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t  nread;
    char *bufp = usrbuf;
    
    while(nleft > 0 )
    {
        if((nread = rio_read(rio, bufp, nleft))==-1)
        {
            return -1;
        }
        else if(nread == 0)
        {
            break;
        }
        nleft -= nread;
        bufp += nread;
    }
    return (n - nleft);
}

ssize_t rio_readline(rio *rp, char *usrbuf, size_t maxlen)
{
    char *bufp = usrbuf;//一个指向字符串的指针
    int nread;
    size_t nleft = maxlen - 1;
    char c;
    while(nleft > 0)
    {
        
        if((nread = rio_read(rp, &c, 1))==-1)
        {
            return -1;
        }
        else if(nread == 0)
        {
            //if(nleft == maxlen - 1) //第一个字符是EOF
              //  return 0;
            break;
        }
        //到这里说明字符串已经读取成功
        *bufp ++ = c;
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
    int fd = open("1.txt", O_RDONLY);
    if(fd == -1)
    {
        ERR_EXIT("open");
    }
    rio_t rio;
    rio_init(&rio, fd);
    char buf[MAXSIZE];
    int ret;
    while((ret =rio_readline(&rio, buf, MAXSIZE)) > 0)
    {
        printf("ret = %d, buf = %s\n", ret, buf);
    }
    close(fd);
    return 0;
}

