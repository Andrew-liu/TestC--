#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Stu
{
    private:
        string name_;
        int age_;
        int score_;
   public:
        Stu(const string &name, int age, int score):name_(name),age_(age),score_(score)
        {}
        ~Stu(){}
        void print() const
        {
            cout << " name=" << name_ << " age=" << age_ << " score=" << score_ << endl;
        }
};

int main(int argc, const char *argv[])
{
    Stu Student("liubin",12,12);
    Student.print();

    return 0;
}
