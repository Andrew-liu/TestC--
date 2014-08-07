#include <stdio.h>
#include <stdlib.h>
#define read_eax()({ \ 
        unsigned int __eax; \ 
        __asm__ __volatile__( \ 
            "movl %%eax,%0" \ 
            :"=r"(__eax)); \
        __eax;})
int main(int argc,char **argv[])
{ 
    int i; 
    printf("HelloWorld MyLady\n"); 
    i = read_eax(); 
    printf("eax = %d\n",i); 
    return 0;}
