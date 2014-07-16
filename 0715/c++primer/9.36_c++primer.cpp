#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<char> vec(100,'a');
    string s;
    char ch;
   // string s(vec.begin(), vec.end());
//    s.assign(vec.begin(), vec.end());
  //  cout << s << endl;
    while(cin >> ch)
    {
        s.push_back(ch);
    }
    cout << s << endl;
    return 0;
}
