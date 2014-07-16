#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    //new是一个运算符
    
    //向系统申请一个int单位,默认为0
    int *ptr=new int;
    cout<< *ptr <<endl;
    
    //申请一个int单位,默认为12
    int *ptr2=new int(12);
    cout << *ptr2 <<endl;

    //申请九块int单位,默认为0
    int *ptr3=new int[9];
    
    delete ptr;
    delete ptr2;
    delete [] ptr3;

    int **s=new int*[3];
    for(int i=0;i!=3;++i)
    {
        s[i]=new int[4];
    }

    for(int y=0;y!=3;++y)
    {
        delete [] s[y];
    }
    delete [] s;

    string **str=new string*[3];
    for(int m=0;m!=3;++m)
    {
        str[m]=new string[4];
    }
    
    for(int n=0;n!=3;++n)
    {
        delete [] str[n];
    }
    delete [] str;


    return 0;
}
