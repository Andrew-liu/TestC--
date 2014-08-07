#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
 * private变量意味着address只能在Parent中被访问
 * Child虽然是派生类，但是无法直接访问
 */
class Parent
{
    private:
        string address_;
};

class Child : public Parent
{
    public:
        string school_;

    void set(const string &address, const string &school)
    {
        address_ = address;
        school_ = school;
    }

    void print() const
    {
        cout << address_ << " " << school_ << endl;
    }
};


int main(int argc, const char *argv[])
{
    Child d;
    d.set("longhua", "wangdao");
    d.print();
    return 0;
}








