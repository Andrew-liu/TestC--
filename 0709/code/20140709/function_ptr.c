#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//该函数的指针类型为
// void (*) (int, int)
void test(int a, int b){
    printf("test\n");
}

void test2(int a, int b){
    printf("test2\n");
}

typedef void (*func) (int, int);

int main(int argc, const char *argv[])
{
    int a;
    int b;
//    void (*pfunc) (int, int) = NULL;
    func pfunc = NULL;
    pfunc = test;
    pfunc(a, b);
    pfunc = test2;
    pfunc(a, b);
    return 0;
}
