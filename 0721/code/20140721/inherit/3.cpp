#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 父类中含有的数据成员
 * 子类中全部都有
 *
 */
class Parent
{
    public:
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








