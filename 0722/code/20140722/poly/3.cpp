#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test
{
    public:
        virtual void test();
        
        int a_;
};

int main(int argc, const char *argv[])
{
    cout << sizeof(Test) << endl;
    return 0;
}
