#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define N 10
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


//10子进程几乎同时消亡,发出10个child信号,
//父进程接收一个child,制定waitpid,回收第一个子进程,然后睡眠
//在整个2s内,第二个child变成待处理,其余丢失,
//睡眠结束,此时存在9个僵尸进程,然后执行9+1次while循环,会全部处理完毕
//处理第二个child,此时没有子进程,waitpid失败,退出
void handler(int sign)
{
    pid_t pid;
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0)
    {
        printf("the child %d is killed!\n", pid);
    }
}

int main(int argc, const char *argv[])
{
    if(signal(SIGCHLD, handler) == SIG_ERR)
    {
        ERR_EXIT("signla");
    }
    pid_t pid;
    for(int i = 0; i < N; ++i)
    {
        if((pid = fork()) < 0)
        {
            ERR_EXIT("fork");
        }
        else if(pid == 0)
        {
            printf("I am a child %d\n",getpid());
            exit(EXIT_SUCCESS);
        }
    }

    char buf[1024];
    int ret;
    while((ret = read(STDIN_FILENO, buf, 1024)) > 0)
    {
        printf("%s\n",buf);
    }

    return 0;
}
