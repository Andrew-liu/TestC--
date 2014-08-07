#include <iostream>
#include <string>
#include <vector>
#include <sys/timerfd.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <poll.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int timerfd;
    if((timerfd = timerfd_create(CLOCK_REALTIME, 0)) == -1)
        ERR_EXIT("timerfd_create");

    struct itimerspec howlong;
    memset(&howlong, 0, sizeof(howlong));
    howlong.it_value.tv_sec = 3; //初始等待时间
    howlong.it_interval.tv_sec = 1; //三秒后间隔时间
    if(timerfd_settime(timerfd, 0, &howlong, NULL) == -1)
            ERR_EXIT("settime");
    char buf[1024] = {0}; 
    struct pollfd tm[1];
    tm[0].fd = timerfd;
    tm[0].events = POLLIN;
    int nread;
    while(1)
    {
        nread = poll(tm, 1, -1);
        if(nread == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("poll");
        }
        else if(nread == 0)
        {
            cout << "timeout" << endl;
        }
        else
        {
            if(read(timerfd, buf, 1024) == -1)
                ERR_EXIT("read");
            cout << "hello" << endl;
        }
        
    }


    close(timerfd);
    return 0;
}
