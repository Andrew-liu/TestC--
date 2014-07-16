#include <iostream>
#include <string>
#include <vector>
using namespace std;
class NoDefault
{
    public:
        NoDefault(int num):num_(num){}
    private:
        int num_;
};
class C
{
    public:
        C():iDefault_(5){}
    private:
        NoDefault iDefault_;
};
int main(int argc, const char *argv[])
{
    C myc;

    return 0;
}
