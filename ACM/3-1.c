#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
int main(int argc, const char *argv[])
{
    int arr[SIZE][SIZE];
    int i,j;
    int count=1;
    for(i=0,j=SIZE-1;i<SIZE-1;i++)
    {
        arr[i][j]=count;
        count++
    }
    for(i=SIZE-1,j=SIZE-1;j>=0;j--)
    {
        arr[i][j]=count;
        count++;
    }
    for(i=SIZE-1,j=0;i<=0;i--)
    {
        arr[i][j]=count;
        count++;
    }
    
    return 0;
}
