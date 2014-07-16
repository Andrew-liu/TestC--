#include <iostream>
#include <string>
#include <vector>
using namespace std;
string add(const string &s1,const string &s2)
{
    return s1+s2;
}
int add(int a,int b)
{
    return a+b;
}
int main(int argc, const char *argv[])
{
    cout<<add("hello","world")<<endl;
    cout<<add(1,2)<<endl;

    return 0;
}
