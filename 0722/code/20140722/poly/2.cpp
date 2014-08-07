#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base
{
    public:
        void print() const
        {
            cout << "In Base" << endl;
        }
};

class Derived : public Base
{
    public:
        void print() const
        {
            cout << "In Derived " << endl;
        }
};



int main(int argc, const char *argv[])
{
    cout << "sizeof Base " << sizeof(Base) << endl;
    cout << "sizeof Derived " << sizeof(Derived) << endl;
    return 0;
}
