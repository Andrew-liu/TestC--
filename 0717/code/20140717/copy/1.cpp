#include <iostream>
#include <string>
#include <vector>
using namespace std;



/*
 *
 * 这里编译器自动为我们提供了一个默认的拷贝构造函数
 *
 */

class Student
{
    public:
        Student()
            :name_(""),
             age_(0),
             score_(0)
        {}

        void set(const string &name, int age, int score)
        {
            name_ = name;
            age_ = age;
            score_ = score;
        }

        void print() const
        {
            cout << name_ << " " <<  age_ << " " << score_ << endl;
        }

    private:
        string name_;
        int age_;
        int score_;
};

int main(int argc, const char *argv[])
{
    Student s;
    s.set("lule", 12, 99);
    
    Student s2(s);
    s2.print();

    return 0;
}
