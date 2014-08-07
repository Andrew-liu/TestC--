#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base
{
    
};

class Derived : public Base
{
    
};

int main(int argc, const char *argv[])
{
    Derived d;

    Base *pb = &d;

    Base b;
    //这里仅仅语法通过，编译器无法检查
    //但是实际中是错误的
    Derived *pd = (Derived *)&b;

    //pb是Base指针，但是实际指向的是
    //Derived对象
    Derived *pd2 = (Derived *)pb;


    return 0;
}







