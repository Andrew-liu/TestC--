#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int g_val = 10;

int main(int argc, const char *argv[])
{
    pid_t pid = fork();    
    if(pid == -1)
        ERR_EXIT("fork");
    else if(pid > 0)
    {
        sleep(3);
        printf("In Parent , val = %d\n", g_val);
        sleep(3);
    }else
    {
        ++g_val;
        printf("In Child, val = %d\n", g_val);
    }
    return 0;
}






