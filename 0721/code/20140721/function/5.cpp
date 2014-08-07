#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
 * 通过子类Studnet s调用的默认是子类自己的版本
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
        cout << id_ << " " << name_
             << " " << age_ << " " 
             << school_ << endl;
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
    //这里显示指定调用父类的版本
    s.Person::set(12, "zhangsan", 23);
    s.print();

   
    return 0;
}
