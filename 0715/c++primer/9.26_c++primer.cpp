#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main(int argc, const char *argv[])
{
    int a[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    int size = sizeof(a) / sizeof(int);
    vector<int> vec(a, a + size);
    list<int>   lst(a, a + size);
    vector<int>::iterator beg = vec.begin();
    list<int>::iterator first =lst.begin();
    while(beg != vec.end())
    {
        if(*beg % 2 == 0)
        {
           beg =  vec.erase(beg);
        }
        else
            ++beg;
    }
    while(first != lst.end())
    {
        if(*first % 2 != 0)
        {
            first = lst.erase(first);
        }
        else
            ++first;
    }
    cout << endl;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << endl;    
    }
    cout << endl;
    for(list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
