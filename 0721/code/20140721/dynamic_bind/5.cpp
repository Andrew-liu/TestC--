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
            cout << "In Base" << endl;
        }

    protected:
        int id_;
        string name_;
        int age_;
};

class Student : public Person
{
    private:
        string school_;


    public:
    void set(int id,
             const string &name,
             int age,
             const string &school)
    {
        id_ = id;
        name_ = name;
        age_ = age;
        school_ = school;
    }


    void print() const
    {
        cout << "In Derived .. " << endl;
    }
};


int main(int argc, const char *argv[])
{
    Student s;
    Person *ptr;
    
    Student *ps = &s;

    //派生类的指针可以直接转化为基类的指针
    ptr = ps;

    Person p1;
    ptr = &p1;

    //这行在语法上可行，但是逻辑上是错误的
    ps = (Student *)ptr;

    ptr = &s;
    ps = (Student *)ptr;
    return 0;
}




