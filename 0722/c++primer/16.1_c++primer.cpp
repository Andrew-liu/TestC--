#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
template <typename T>

T myabs(const T &a)
{
    return a > 0 ? a :-a;
}
template <typename T, typename V>
T &print( T &os, const V &n)
{
    os << n << endl;
    return os;
}
int main(int argc, const char *argv[])
{
    //double a=-2.3, b;
    //int a= -3, b;
    //b = myabs(a);
    //cout << b << endl;
    ofstream out;
    out.open("1.txt");
    ostringstream os;
    print(out,"hello");
    //cout << os.str() << flush;

    return 0;
}
