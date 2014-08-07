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

/*
 * 与exec的例子做比较
 *
 *
 */

int main(int argc, const char *argv[])
{
    printf("Enter main .....\n");
    

    system("ls");  //执行ls

    printf("Leave main ......\n");

    return 0;
}
