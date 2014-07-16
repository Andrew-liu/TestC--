#include <iostream>
#include <string>
#include <vector>
using namespace std;
int max_num(int a,int *b)
{
    int max;
    if(a>*b)
    {
        max=a;
    }
    else
    {
        max=*b;
    }
    return max;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swap1(int *&a,int *&b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(int argc, const char *argv[])
{
    int i=3,j=4;
//    int *b=&j;
//    cout<<max_num(i,&j)<<endl;    
    int *a=&i;
    int *b=&j;
//    swap(a,b);
    swap1(a,b);

    cout<<*a<<" " <<*b<<endl;
    return 0;
}
