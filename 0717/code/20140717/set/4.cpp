#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char *argv[])
{
    set<int> s;
    

    s.insert(99);
    s.insert(23);
    s.insert(1);
    s.insert(108);
    s.insert(77);


    s.erase(77);
    
    set<int>::iterator ret = s.find(108);
    if(ret == s.end()){
        cout << "Not Found" << endl;
    }else{
        s.erase(ret);
    }

    cout << s.size() << endl;
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << endl;
    }


    return 0;
}
