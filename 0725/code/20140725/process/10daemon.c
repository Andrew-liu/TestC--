#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    pid_t pid;
    if((pid = fork()) < 0)
        ERR_EXIT("fork");
    else if(pid > 0)
        exit(EXIT_SUCCESS);  // 确保出现孤儿进程


    setsid();  //创建一个新的会话 脱离shell的会话期
    chdir("/");  //更改工作目录
    umask(0);
    /*
       int i;
       for(i = 0; i < 3; ++i)
       close(i); 
       open("/dev/null");  // 打开0
       dup(0);  //1
       dup(0); // 2
       */

    // /dev/null 
    // 如果stdin重定向到/dev/null，那么一旦尝试read，立刻返回EOF
    // 如果是stdout stderr，输出全部被丢弃
    int fd = open("/dev/null", O_WRONLY);
    if(fd == -1)
        ERR_EXIT("open");
    dup2(fd, STDIN_FILENO);
    dup2(fd, STDOUT_FILENO);
    dup3(fd, STDERR_FILENO);
    close(fd);

    while(1) ;
    return 0;
}
