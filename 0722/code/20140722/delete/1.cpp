#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base
{
    public:
    Base()
    {
        cout << "Base ..." << endl;
    }
    ~Base()
    {
        cout << "~Base ..." << endl;
    }
};

class Derived : public Base
{
    public:
        Derived()
        {
            cout << "Derived ... " << endl;
        }
        ~Derived()
        {
            cout << "~Derived ..." << endl;
        }
};


int main(int argc, const char *argv[])
{
    
    Base *pb = new Derived;


    delete pb;


    return 0;
}
