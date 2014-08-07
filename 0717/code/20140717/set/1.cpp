#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char *argv[])
{
    set<int> s;

    for (int i = 0; i < 10; i++) {
        s.insert(i);
    }

    cout << s.size() << endl;
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << endl;
    }


    return 0;
}
