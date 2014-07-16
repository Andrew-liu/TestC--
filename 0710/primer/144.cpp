#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    
    vector<string *> s;
    string str;
    while(cin>>str)
    {
        string *p=new string;
        *p=str;
        s.push_back(p);
        
    }
    for(vector<string *>::iterator ix=s.begin();ix!=s.end();++ix)
    {
        cout<<**ix<<" "<<(**ix).size() <<endl;
    }
    return 0;
}
