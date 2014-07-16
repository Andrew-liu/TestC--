#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, const char *argv[])
{
    int i;
    int *ptr=(int *)malloc(9*sizeof(int));//动态分配数组
    free(ptr);
    //动态生成二维数组 3*4
    int **arr = (int **)malloc (3*sizeof(int *));
    for(i=0;i!=3;i++)
    {
        arr[i]=(int *)malloc(4*sizeof(int));
    }

    for(i=0;i!=3;i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
