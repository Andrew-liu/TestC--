#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 实现一个函数，打印这个二维数组
 */


/*
 * 这种写法是错误的，原因是这里接收int **, 但是main中的A实际上是
 * int (*)[4] 
 * 这叫做数组的指针，指向一个长度为4的数组
 */
//void print(int **A, int m, int n){
void print(int (*A)[4], int m){
    int i, j;
    for(i = 0; i != m; ++i){
        for(j = 0; j != 4; ++j){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}



int main(int argc, const char *argv[])
{
    int A[3][4];
    print(A, 3);
    return 0;
}
