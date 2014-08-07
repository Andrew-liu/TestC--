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


int my_system(const char *command)
{
    pid_t pid;
    if(command == NULL)
        return 1;
    int status;

    if((pid = fork()) < 0)
        ERR_EXIT("fork");
    else if(pid == 0)
    {
        execl("/bin/sh", "sh", "-c", command, NULL);
        exit(EXIT_FAILURE); //如果正确，不会执行到这里
    }else
    {
        while(waitpid(pid, &status, 0) < 0)
        {
            if(errno == EINTR)   //如果是中断 需要重新执行
                continue;

            status = -1;
            break;              //如果不是中断，直接退出
        }
    
    }
    return status;
}


int main(int argc, const char *argv[])
{
    printf("Enter main .....\n");
    

    my_system("ls");  //执行ls

    printf("Leave main ......\n");

    return 0;
}
