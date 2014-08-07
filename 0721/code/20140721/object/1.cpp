#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 子类对象赋值给父类对象
 * 对象的切除
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
    Person p1;
    Student s1;
    s1.set(123, "zhangsan", 45, "longhua");
    s1.print();

    p1 = s1;//
    p1.print();
    return 0;
}
