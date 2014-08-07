#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
 * 子类可以正常调用从父类继承而来的函数
 *
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
    s.print();
    return 0;
}
