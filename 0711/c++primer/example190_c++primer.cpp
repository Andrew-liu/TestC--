#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    
    int threshold=10;
    string s;
    vector<string> word;
    while(cin>>s&& !s.empty())
    {
    //    word.push_back(s);
    
    if(s.size()<threshold)
    {
        cerr<<"Error:"<<__FILE__
            <<":line "<<__LINE__<<endl
            <<" compile on"<<__DATE__
            <<"at "<<__TIME__<<endl
            <<" word read was "<<s
            <<" length too short "<<endl;
    }
    }
    return 0;
}
