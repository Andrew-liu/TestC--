#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    public:
        Student(const string name,
                int age,
                int score)
            :name_(name), age_(age), score_(score)
        {
            
        }

        ~Student()
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
    Student s("zhangsan", 23, 77);
    s.print();
    return 0;
}
