#include <iostream>
#include <string>
#include <vector>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

string add(const string &a, const string &b)
{
    return a + b;
}

int main(int argc, const char *argv[])
{
    int a = add(2, 3);
    string s = add("hello", "world");


    cout << a << endl;
    cout << s << endl;
    return 0;
}



