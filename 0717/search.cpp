#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{   
    public:
        Student():name_(""), age_(0), score_(0)
        {}
        
        Student(const string &name, int age, int score):
            name_(name),
            age_(age),
            score_(score)
        {}
       
        void set(const string &name, int age, int score)
        {
            name_ = name;
            age_ = age;
            score_ = score;
        }
        Student(const Student &other):
            name_(other.name_),
            age_(other.age_),
            score_(other.score_)
        {}
        void print()
        {
            cout << "name=" << name_ << " age=" << age_ << " score=" << score_ <<endl;
        }
    private:
        string name_;
        int    age_;
        int    score_;
};

int main(int argc, const char *argv[])
{
    Student stu;
    Student ss("liubin", 1, 20);
    stu.set("liubin", 20, 99);
    Student s(stu);
    s = ss;
    s.print();
    return 0;
}
