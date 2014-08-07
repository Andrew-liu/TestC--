#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    //打开目录
    DIR *dir = opendir(".");
    if(dir == NULL)
        ERR_EXIT("opendir");

    struct dirent *de;
    //readdir返回下一个目录结点
    while((de = readdir(dir)) != NULL)
    {
        printf("%s\n", de->d_name);
    }

    closedir(dir);










    return 0;
}
