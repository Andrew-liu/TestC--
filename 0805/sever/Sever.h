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

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)



class Sever
{
    public:
        Sever();
        ~Sever(){}
        int init_socket();
        virtual void wait() = 0;
        virtual void handle_accept() = 0;
        virtual void handle_data() {};
    protected:
        int listenfd_;

};

ssize_t readn(int fd, char *usrbuf, size_t n);
ssize_t writen(int fd, char *usrbuf, size_t n);
ssize_t recv_peek(int sockfd, char *usrbuf, size_t n);
ssize_t readline(int sockfd, char *usrbuf, size_t maxline);



#endif

