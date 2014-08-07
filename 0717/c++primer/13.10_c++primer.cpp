#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee
{
    public:
        Employee(const string &name):name_(name),id_(couter)
        {
            couter++;
        }
        Employee(const Employee &other):name_(other.name_),id_(couter)
        {}
        Employee &operator = (const Employee &other)
        {
            name_ = other.name_;
            return *this;
        }
    private:
        string name_;
        int    id_;
        static int couter;

}

int couter = 0;

int main(int argc, const char *argv[])
{
    Employee people;
    Employee emp = people;

    return 0;
}

