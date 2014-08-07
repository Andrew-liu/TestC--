#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE *fp = fopen("test.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "open file failed!\n");
        exit(EXIT_FAILURE);
    }

    char buf[1024];
    fgets(buf, 1000, fp);

    printf("read: %s\n", buf);
    
    fclose(fp);
    return 0;
}
