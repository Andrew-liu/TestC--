#include "Sever.h"

ssize_t readn(int fd, char *usrbuf, size_t n)
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

ssize_t writen(int fd, char *usrbuf, size_t n)
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

//recv_peek选项完成一次正确的读取过程。
ssize_t recv_peek(int sockfd, char *buf, size_t len) {
    int nread;
    while (1) {
        //这个过程只成功调用一次
        nread = recv(sockfd, buf, len, MSG_PEEK);
        if (nread < 0 && errno == EINTR) {  //被中断则继续读取
            continue;
        }
        if (nread < 0) {
            return -1;
        }
        break;
    }
    return nread;
}


ssize_t readline(int sockfd, char *buf, size_t maxline) {
    int nread;  //一次IO读取的数量
    int nleft;  //还剩余的字节数
    char *ptr;  //存放数据的指针的位置
    int ret;    //readn的返回值
    int total = 0;  //目前总共读取的字节数

    nleft = maxline-1;
    ptr = buf;

    while (nleft > 0) {
        //这一次调用仅仅是预览数据
        //并没有真的把数据从缓冲区中取走
        ret = recv_peek(sockfd, ptr, nleft);
        //注意这里读取的字节不够，绝对不是错误！！！
        if (ret <= 0) {
            return ret;
        }

        nread = ret;
        int i;
        for (i = 0; i < nread; ++i) {
            if (ptr[i] == '\n') {
                //这里才是真正的读取过程
                ret = readn(sockfd, ptr, i + 1);
                if (ret != i + 1) {
                    return -1;
                }
                total += ret;
                ptr += ret;
                *ptr = 0;
                return total;   //返回此行的长度 '\n'包含在其中
            }
        }
        //如果没有发现\n，这些数据应全部接收
        ret = readn(sockfd, ptr, nread);
        if (ret != nread) {
            return -1;
        }
        nleft -= nread;
        total += nread;
        ptr += nread;
    }
    *ptr = 0;
    return maxline-1;
}

Sever::Sever() 
{
    listenfd_ = init_socket();
}

int Sever::init_socket()
{
    if((listenfd_ = socket(AF_INET, SOCK_STREAM,0)) == -1)
    {
        ERR_EXIT("socket");
    }

    int on = 1;
    if(setsockopt(listenfd_, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    {
        ERR_EXIT("setsockopt");
    }

    struct sockaddr_in severaddr;
    memset(&severaddr, 0, sizeof(severaddr));
    severaddr.sin_family = AF_INET;
    severaddr.sin_port = htons(8888);
    severaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listenfd_, (struct sockaddr *)&severaddr, sizeof(severaddr)) < 0)
    {
        ERR_EXIT("bind");
    }
    if(listen(listenfd_, SOMAXCONN) < 0)
        ERR_EXIT("Listen");
    return listenfd_;
}
