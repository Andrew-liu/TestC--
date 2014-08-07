#ifndef _SEVER_
#define _SEVER_
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <functional>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)



class Sever
{
    public:
        typedef std::function<void (int, char *)> HandleCallback;
        Sever();
        ~Sever(){}
        int init_socket();
        virtual void wait() = 0;
        virtual void handle_accept() = 0;
        virtual void handle_data() {};
        virtual void setcallback(const HandleCallback &callback) = 0;
    protected:
        int listenfd_;
        HandleCallback callback_;

};

ssize_t readn(int fd, char *usrbuf, size_t n);
ssize_t writen(int fd, char *usrbuf, size_t n);
ssize_t recv_peek(int sockfd, char *usrbuf, size_t n);
ssize_t readline(int sockfd, char *usrbuf, size_t maxline);



#endif

