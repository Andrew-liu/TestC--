#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
    int a[5]={23,1,45,87,25};
    //sort需要提供的区间是一个左闭右开的区间,在c++标准库算法中需要提供的区间全部为左闭右开的区间
    sort(a,a+5);
    for(int i=0;i!=5;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

