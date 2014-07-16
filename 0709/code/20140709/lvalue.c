#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    //i是一个左值， 10是右值
    int i = 10;

    //p是左值， *p 是右值
    const int *p = &i;
    
    // q是右值，*q是左值
    int * const q = &i;


    const char *s = "hello";
    s[0] = 'w';

    return 0;
}
