#include "Poll_t.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void print(int peerfd, char *buf)
{
    printf("recv from %s", buf);
    writen(peerfd, buf, strlen(buf));
}

int main(int argc, const char *argv[])
{
    Poll_t p;
    p.setcallback(print);
    while(1)
    {
        p.wait();
        p.handle_accept();
        p.handle_data();
    }
    return 0;
}
