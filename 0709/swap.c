#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int swap(int **a,int **b)//在加一次*
{
    int *temp=*a;
    *a=*b;
    *b=temp;
}
int main(int argc, const char *argv[])
{
    int i=5,j=10;
    int *a=&i;
    int *b=&j;
//    printf("%d %d\n",&a,&b);
    swap(&a,&b);//交换的是int *类型
    printf("%d %d\n",a,b);
    return 0;
}
