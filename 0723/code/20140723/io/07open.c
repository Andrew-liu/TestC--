#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    //O_WRONLY 只写
    //O_CREAT 文件不存在则创建
    //O_TRUNC 清空文件
    //以只写方式打开，如果文件不存在则创建
    //如果存在则清空文件
    int fd = open("1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd == -1)
        ERR_EXIT("open");

    char buf[100] = "beijing";
    write(fd, buf, strlen(buf));

    close(fd);


    return 0;
}
