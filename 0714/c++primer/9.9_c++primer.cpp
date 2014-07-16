#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std;
int main(int argc, const char *argv[])
{
    list<int> mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(3);
    mylist.push_back(4);
    mylist.push_back(5);
    mylist.push_back(6);
    mylist.push_back(7);
    mylist.push_back(8);
    mylist.push_back(9);
    mylist.push_back(10);
    for (list<int>::iterator ix = --(mylist.end()); ix != --mylist.begin(); --ix)
    {
        cout << *ix <<endl;
    }
  //  const vector<int> vec(10);
//    vector<int>::iterator it = vec.begin();
    vector<string> svec(10);
    vector<string>::iterator it = svec[0];

    return 0;
}
