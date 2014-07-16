#include <iostream>
#include <string>
#include <vector>
using namespace std;
void make_plural(string &str,const char ch='s')
{
    int  it=str.size()-1;
    if(str[it]!=ch)
    {
        str+=ch;
    }
    

}

int main(int argc, const char *argv[])
{
    string str;
    while(cin>>str)
    {
        make_plural(str);
        cout<<"plural :"<<str<<endl;
    }
    return 0;
}
