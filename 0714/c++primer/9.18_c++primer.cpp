#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;
int main(int argc, const char *argv[])
{
    
    list<int> lst;
    deque<int> odd;
    deque<int> nodd;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    for(list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        if((*it)%2 == 0)
        {
            nodd.push_back(*it);
        }
        else
        {
            odd.push_back(*it);
        }
    }
    for(deque<int>::iterator it = nodd.begin(); it != nodd.end(); ++it)
    {
        cout << *it << endl;    
    }
    for(deque<int>::iterator it = odd.begin(); it != odd.end(); ++it)
    {
        cout << *it << endl;    
    }
    return 0;
}
