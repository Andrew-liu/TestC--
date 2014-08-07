#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


int main(int argc, char *argv[])
{
    // exe -t -n 9 
    int opt;
    while(1)
    {
        opt = getopt(argc, argv, "tn:");
        if(opt == '?')
            exit(EXIT_FAILURE);
        if(opt == -1)
            break;  //解析结束

        switch(opt)
        {
            case 't':
                printf("-t\n");
                break;
            case 'n':
                //optarg是一个全局变量
                printf("-n : %d\n", atoi(optarg));
                break;
        }
    }


    return 0;
}
