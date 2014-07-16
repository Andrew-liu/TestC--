#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    
    list<string> lst;
    lst.push_back("hello");
    lst.push_back("world");
    lst.push_back("how");
    lst.push_back("are");
    lst.push_back("you");
    lst.push_back("world");
    list<string>::iterator it;
    list<string> lst2;
    lst2.push_back("hello");

    it = find(lst.begin(), lst.end(), "world");
    cout << *it << endl;
    lst.swap(lst2);
    cout << *it <<endl;

    
    return 0;
}
