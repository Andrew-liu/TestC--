#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string str("ab2c3d7R4E6");
    string num("0123456789");
    string::size_type pos = 0;
    while((pos = str.find_first_not_of(num, pos)) !=string::npos)
    {
        cout << pos << endl;
        ++pos;
    }
    return 0;
}
