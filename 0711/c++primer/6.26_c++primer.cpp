#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
int main(int argc, const char *argv[])
{
    
    string s;
    /*
    while(cin>>s)
    {
        assert(cin);
        cout<<"string :"<<s<<endl;
        }
        */
    while(cin>>s && !s.empty() ){}
    assert(cin);
    cout<<"string: "<<s<<endl;
    return 0;
}
