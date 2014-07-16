#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{

    int a;
    if(cin.good())
    {
        cout<<"cin is good"<<endl;
    }
    while(cin>>a)
    {
        cout<<a<<endl;
    }
    if(cin.eof())
    {
        cout<<"cin is eof"<<endl;
    }
    if(cin.fail())
    {
        cout<<"cin is failed"<<endl;
    }
    string s;
    cin>>s;
    cout<<s<<endl;
    return 0;
}
