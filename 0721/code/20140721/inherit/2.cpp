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
};


int main(int argc, const char *argv[])
{
    Child d;
    d.address_ = "longhua";
    d.school_ = "wangdao";    

    cout << d.address_ << endl;
    cout << d.school_ << endl;

    return 0;
}








