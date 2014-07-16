#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
void swap(int *a, int *b){
    int *temp = a;
    a = b;
    b = temp;
}
*/

void swap(int **a, int **b){
    int *temp = *a;
    *a = *b;
    *b = temp;
}

//交换两个八级指针 int ********
void swap_8(int *********a, int *********b){
    int ********temp = *a;
    *a = *b;
    *b = temp;
}



int main(int argc, const char *argv[])
{
    int i, j;
    int *a = &i;
    int *b = &j;
    swap(&a, &b);
    return 0;
}
