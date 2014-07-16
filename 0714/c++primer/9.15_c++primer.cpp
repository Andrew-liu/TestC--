#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main(int argc, const char *argv[])
{
    list<string> mylist;
    string s;
    while(cin >> s)
    {
        mylist.push_back(s);
    }

    for(list<string>::iterator it = mylist.begin(); it != mylist.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
