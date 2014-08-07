#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person
{
    public:
        virtual void set(int id, string name)
        {
            id_ = id;
            name_ = name;
        }
        virtual void print()
        {
            cout << "Person" << endl;
            cout << id_ << " " << name_ << endl;
        }
    protected:
        int id_;
        string name_;
};

class Student : public Person
{
    public:
        void set(int id, const string &name, const string &school)
        {
            id_ = id;
            name_ = name;
            school_ = school;
        }
        void print()
        {
            cout << "Student" << endl;
            cout << id_ << " " << name_ << " " <<school_ <<endl;
        }
    private:
        string school_;
};
int main(int argc, const char *argv[])
{
    Student s;
    s.set(1, "liubin", "wangdao");
    Person p(s);
//    Person *p = &s;
//    p->print();
    p.print();
    return 0;
}
