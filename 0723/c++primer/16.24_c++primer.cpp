#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename U>
int mycmp(const T &a, const U &b)
{
    if(a < b) return -1;
    if(b < a) return 1;
    return 0;
}

int main(int argc, const char *argv[])
{
    int flag;
    int a = 3;
    short b = 4;
    //flag = mycmp<int, short>(a, b);
    string s1 = "hello", s2 = "world";
//    flag = mycmp<string, string>(s1, s2);
    cout << mycmp<string, string>(string("hello"), string("world")) << endl;
    return 0;
}
