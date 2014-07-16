#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>
using namespace std;
int main(int argc, const char *argv[])
{
    int x;
    while(cin>>x,!cin.eof())
    {
        if(cin.bad())
        {
            throw runtime_error("cin error");
        }
        if(cin.fail())//输入错误的时候为1
        {
            cerr<<"input again"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
    }
    string s="hello";
    cin>>s;
    cout<<"good "<<cin.good()<<endl;
    cout<<"fail "<<cin.good() <<endl;
    cout<<s<<endl;

    return 0;
}
