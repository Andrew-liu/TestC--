#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Y;
class X
{
    private:
        int num_;
        Y *my_;
};
class Y
{
    private:
        X myx_;
};
int main(int argc, const char *argv[])
{
    
    return 0;
}
