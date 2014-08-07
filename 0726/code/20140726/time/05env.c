#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;  //这里使用了系统的一个全局变量



int main(int argc, const char *argv[])
{
    int i;
    for(i = 0; environ[i] != NULL; ++i)
        printf("%s\n", environ[i]);
    return 0;
}
