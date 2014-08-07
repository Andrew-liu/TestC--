#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    //获取用户的ID
    printf("uid = %d\n", getuid());
    //获取有效的用户ID
    printf("euid = %d\n", geteuid());
    return 0;
}





