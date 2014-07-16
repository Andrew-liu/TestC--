#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*func)(int, int);//给void (*)(int, int)一个别名



//该函数的函数指针的类型
void test(int a,int b)
{
    printf("test\n");
}
int main(int argc, const char *argv[])
{
    int a, b;
    //定义变量 类型加上变量名
    void (*pfunc)(int, int)=NULL;
    pfunc=test;
    pfunc(a, b);

    return 0;
}
