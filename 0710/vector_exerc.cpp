#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, const char *argv[])
{
    string s;
    while(cin>>s)
    {
        for(string::iterator it=s.begin();it!=s.end();++it)
        {
            if(*it>='A' && *it<='Z')
            {
                (*it)+=32;
            }
            else if( *it>='a'&& *it<='z')
            {
                (*it)-=32;
            }
        }
        cout<< "after change :"<< s<<endl;
    }
    return 0;
}
