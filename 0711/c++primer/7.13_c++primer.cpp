#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum1(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
    }
    return sum;
}

int sum2(int *a,int n)
{
    int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
    }
    return sum;
}

int sum3(int (&a)[10])
{
    int sum=0;
    for(int i=0;i!=10;++i)
    {
        sum+=a[i];
    }
    return sum;
}

int main(int argc, const char *argv[])
{
    
    int a[10];
    for(int i=0;i!=10;++i)
    {
        a[i]=i+1;
    }
    cout<< "sum1"<<sum1(a,10)<<endl;
    cout<<"sum2"<<sum2(a,10)<<endl;
    cout<<"sum3"<<sum3(a)<<endl;
    return 0;
    return 0;
}
