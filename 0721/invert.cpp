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
    Base b;
    Derived *pd = (Derived *)&b;
    Derived de;
    Base *pb;
    pb = &de;
    Derived *ptr = (Derived *)pb;
    return 0;
}
