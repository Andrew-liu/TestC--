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
    
    ptr = &s;
    //ptr以为自己指向的是Person对象
    //调用的就是Person的版本
    ptr->print();
    return 0;
}




