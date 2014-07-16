#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main(int argc, const char *argv[])
{
    
    vector<int> vec;
    list<int> lst;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    vector<int>::iterator beg = vec.begin();
    list<int>::iterator beg2 = lst.begin();
    while(beg !=  vec.end() && beg2 !=lst.end())
    {
        if(*beg != *beg2)
        {
            break;
        }
        else
         {
            ++beg;
            ++beg2;
         }
    }
    if(beg == vec.end() && beg2 == lst.end())
    {
        cout << " = " << endl;
    }
    else
    {
        cout << "!= " << endl;
    }
    return 0;
}
