#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
#define N 10

/*
 *通过封装二维数组到一个结构体中，可以方便的传递二维数组
 *
 */
typedef struct Array
{
    int A_[M][N];
    int m_;
    int n_;
}Array;

//通过传入结构体的地址，对结构体中的二位数组进行操作。
void print1(Array *arr)
{
    int i,j;
    for(i=0;i!=arr->m_;i++)
    {
        for(j=0;j!=arr->n_;j++)
        {
            printf("%d ",arr->A_[i][j]);    
        }
        printf("\n");
    }
}
/*
 *z这种写法是错误的，原因是这里接受int **,但是main中的A实际上是int(*)[4]
 *这叫做数组的指针，只想一个长度为4的数组
 *void prinf(int **A,int m,int n){}
 */

void print(int (*A)[4],int m)//数组的指针，
{
    int i,j;
    for(i=0;i!=m;i++)
    {
        for(j=0;j!=4;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, const char *argv[])
{
    int A[3][4]={0};
    print(A,3);//传入函数后，丢失第一维维度，要把第一维数值传入函数
    Array Max;
    memset(&Max,0,sizeof(Max));
    Max.m_=4;
    Max.n_=3;
    print1(&Max);
    return 0;
}
