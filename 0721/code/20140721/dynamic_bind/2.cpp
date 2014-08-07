#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
 * 基类的指针可以指向派生类的对象
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

};


int main(int argc, const char *argv[])
{
    Student s;
    Person *ptr;
    
    ptr = &s;
    
    //这几个函数从父类继承而来，可以用父类的指针正常调用
    ptr->set(12, "zhangsan", 22);
    ptr->print();

    return 0;
}




