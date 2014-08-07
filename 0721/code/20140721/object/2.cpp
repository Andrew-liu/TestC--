#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base
{
    public:
        Base()
        {
            cout << "Base ..... " << endl;
        }
        ~Base()
        {
            cout << "~Base ..... " << endl;
        }
};

class Other
{
    public:
        Other()
        {
            cout << "Other ..... " << endl;
        }
        ~Other()
        {
            cout << "~Other ..... " << endl;
        }
};

class Derived : public Base
{
    public:
        Derived()
        {
            cout << "Derived ..... " << endl;
        }
        ~Derived()
        {
            cout << "~Derived ....." << endl;
        }
    private:
        Other other_;
};


int main(int argc, const char *argv[])
{
    Derived d;
    return 0;
}



