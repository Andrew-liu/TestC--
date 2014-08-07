#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test
{
    public:
        int operator () (const int a, const int b, const int c)
        {
            if(a > 0)
            {
                return b;
            }
            else
            {
                return c;
            }
        }
    private:
        int num_;
};
int main(int argc, const char *argv[])
{
    Test test;
    int num = test(1,2,3);
    cout << num << endl;
    return 0;
}
