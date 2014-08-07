#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
class GT_ls
{
    public:
        GT_ls(const string str):str_(str)
    {}
        bool operator () (const string &s)
        {
            return str_ == s;
        }
    private:
        string str_;
};
int main(int argc, const char *argv[])
{
    vector<string> s;
    string str;
    while(cin >> str, !cin.eof())
    {
        s.push_back(str);
    }
    cout << count_if(s.begin(), s.end(), GT_ls("hello")) << endl;
    return 0;
}
