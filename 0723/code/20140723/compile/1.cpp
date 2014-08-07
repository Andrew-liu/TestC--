#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Test
{
    public:
        int a_;
};

int main(int argc, const char *argv[])
{
    map<Test, int> m;

    Test t;
    //这里是错误的，因为没有< 操作符
    m[t] = 1;

    return 0;
}



