#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string s("heLLowoRLd");
    string::iterator it = s.begin();
    while(it != s.end())
    {
        if(isupper(*it))
        {
            it = s.erase(it);
        }
        else
            ++it;
    }

    cout << s << endl;
    return 0;
}
