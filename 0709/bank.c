#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int g_account=1000;

void *thread_A(void *arg)
{
    while(1)
    {
        int temp = g_account;
        temp+=100;
        sleep(3);
        g_account=temp;
    }
}

void *thread_B(void arg)
{
        
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
