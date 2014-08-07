#include "Epoll_t.h"
#include "Sever.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void print(int peerfd, char *buf)
{
    printf("recv from %s", buf);
    writen(peerfd, buf, strlen(buf));
}

int main(int argc, const char *argv[])
{
    Epoll_t test(print);
    while(1)
    {
        test.wait();
        test.handle();
    }
    return 0;
}
