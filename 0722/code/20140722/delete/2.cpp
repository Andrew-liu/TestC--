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
    virtual ~Base()
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
        //这里的析构函数尽管不重名，但是也是一个虚函数
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
