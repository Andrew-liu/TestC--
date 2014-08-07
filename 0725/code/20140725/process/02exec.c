#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char *argv[])
{
    printf("Enter main ......\n");

    //使用command中的代码替换当前进程映像 
    execlp("ls", "ls", "-l", NULL);

    printf("Leave main .......\n");
    return 0;
}
