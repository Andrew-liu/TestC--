#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 子类的多参数构造函数，如何去初始化父类的private变量
 * 在初始化列表中，直接调用父类的相应构造函数
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
    Student(int id,
            const string &name,
            int age,
            const string &school)
        :Person(id, name, age), school_(school)
    {}


    void print() const
    {
        Person::print();
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
    Student s(123, "lisi", 32, "longhua");
    s.print();
    return 0;
}
