#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int swap(int *********a,int *********b)//在加一次*
{
    int ********temp=*a; //解一层引用
    *a=*b;
    *b=temp;
}
int main(int argc, const char *argv[])
{
    int i,j;
    int ********a=&i;
    int ********b=&j;
    printf("%p %p\n",a,b);
    swap(&a,&b);//交换的是int *******类型
   printf("%p %p\n",a,b);
    return 0;
}
