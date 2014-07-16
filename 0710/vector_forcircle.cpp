#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> vec;
    vec.push_back("hello");
    vec.push_back("world");
    vec.push_back("how");
    vec.push_back("are");
    vec.push_back("you");
//auto是C++11提供的新特性,具有自动推断功能
    for(const auto &s :vec)
    {
        cout<< s <<endl;
    }

    emanticor(auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
