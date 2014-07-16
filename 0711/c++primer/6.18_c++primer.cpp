#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string s1,s2;
    string s;
    do
    {
        cout<<"input two number:"<<endl;
        cin>>s1>>s2;
        if(s1>s2)
        {
            cout<<"lower"<<s2<<endl;
        }
        else
        {
            cout<<"lower"<<s1<<endl;
        }
        cout<<"input yes or no:"<<endl;
        cin>>s;
    }while(s!="no");
    return 0;
}
