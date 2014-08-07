#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define N 10
int main(int argc, const char *argv[])
{
    pid_t pid[N]; //存储子进程ID

    int i;
    for(i = 0; i < N; ++i)
    {
        //父进程创建完子进程继续循环
        //子进程直接退出
        pid[i] = fork();
        if(pid[i] == -1)
            ERR_EXIT("fork");
        else if(pid[i] == 0)
            exit(100 + i); //子进程返回了状态码
    }

    pid_t ret;
    int status; //接收子进程的状态 
    i = 0;
    while((ret = waitpid(pid[i], &status, 0)) > 0)
    {
        if(WIFEXITED(status)) //如果该进程正常退出
            printf("child %d terminated normally with code: %d\n", ret, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally !\n", ret);

        ++i;
    }


    /*
     * 按序接收子进程
     *
     *
     */


    //创建10个子进程，waitpid在循环内执行了11次
    //最后一次是失败的
    if(errno != ECHILD)
        ERR_EXIT("waitpid");
    return 0;
}
