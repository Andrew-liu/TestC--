#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
        Student() {}
        Student(int id,
                const string &name,
                int age,
                const string &school)
            :Person(id, name, age), school_(school)
        {}

        //这里应该复制父类的对象
        Student(const Student &other)
            :Person(other), school_(other.school_)
        {}

        Student &operator=(const Student &other)
        {
            if(this != &other)
            {
                //显式调用父类的赋值运算符
                Person::operator=(other);
                school_ = other.school_; 
            }

            return *this;
        }

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
    Student s2; 
    s2 = s; //这里调用Student的赋值运算符
    s2.print();
    return 0;
}
