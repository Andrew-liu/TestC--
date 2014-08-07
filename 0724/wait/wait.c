#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    pid_t pid;
    if((pid = fork()) == -1)
    {
        ERR_EXIT("fork");        
    }
    else if(pid > 0)
    {
        printf("my child <%d>\n",pid);
        sleep(3);
        pid_t ret = wait(NULL);
        printf("the child <%d> has been killed\n",ret);
    }
    else
    {
        printf("I am a child <%d>\n",getpid());
        exit(0);
    }
    return 0;
}
