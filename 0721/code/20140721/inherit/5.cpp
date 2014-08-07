#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Protected意味着该成员可以在本类以及他的child类中被访问
 *
 */
class Parent
{
    protected:
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








