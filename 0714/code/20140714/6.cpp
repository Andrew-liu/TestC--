#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    public:
 
        /*
        Student()
            :name_(""), age_(-1), score_(-1)
        {
        
        } */

        Student(const string name,
                int age,
                int score)
            :name_(name), age_(age), score_(score)
        {
            
        }

        void print() const{
            cout << name_ << " " << age_ << " " << score_ << endl;
        }

    private:
        string name_;
        int age_;
        int score_;
};


int main(int argc, const char *argv[])
{
    //这里调用的是Student的无参数构造函数
    //Student *ps = new Student;

    //调用自定义的构造函数
    Student *ps = new Student("zhangsna", 34, 67);

    Student *ps2 = new Student[10];
    return 0;
}
