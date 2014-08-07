#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Bar;

class Foo
{   
    friend class Bar;
    public:
        Foo(int val):ival_(val)
    {}
        int getFoo()
        {
            return ival_;
        }
    private:
        int ival_;
};
class Bar
{
    public:
        Foo Fooval()
        {
            callsFooval++;
            return foo_;
        }
        
    private:
        static int val_;
        static Foo foo_;
        static int callsFooval;
};
int Bar::val_ = 20;
int Bar::callsFooval = 0;
Foo Bar::foo_(0);
int main(int argc, const char *argv[])
{
    Foo foo(5);
    int ret = foo.getFoo();
    cout << ret << endl;
    return 0;
}
