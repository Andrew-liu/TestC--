#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main(int argc, const char *argv[])
{
    list<char *> lst;
    vector<string> vec ;
    lst.push_back("hello");
    lst.push_back("hello");
    lst.push_back("hello");
    lst.push_back("hello");
    lst.push_back("hello");

    vec.assign(lst.begin(), lst.end());
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;    
    }
    return 0;
}
