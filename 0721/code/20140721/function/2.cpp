#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
 * 子类编写的函数，仍可以正常使用
 *
 */
class Person{
    public:
        Person(){}
        Person(int id,
               const string &name,
               int age)
            :id_(id),
             name_(name),
             age_(age)
        {}

        void set(int id,
                 const string &name,
                 int age)
        {
            id_ = id;
            name_ = name;
            age_ = age;
        }

        void print() const
        {
            cout << id_  << " " << name_ << " " << age_ << endl;
        }

    private:
        int id_;
        string name_;
        int age_;
};

class Student : public Person
{
    private:
        string school_;
    public:
        /*
         * 它们是子类自行编写的函数
         */
        void set_school(const string &school)
        {
            school_ = school;
        }

        void print_school()
        {
            cout << school_ << endl;
        }
};

class Programmer : public Person
{
    private:
        string language_;
};


int main(int argc, const char *argv[])
{
    Student s;
    s.set(12, "lisi", 45);
    s.set_school("longhua");
    s.print();
    s.print_school();
    return 0;
}
