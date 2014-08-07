#include "Poll_t.h"
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
    Poll_t p(print);
    while(1)
    {
        p.wait();
        p.handle_accept();
        p.handle_data();
    }
    return 0;
}
