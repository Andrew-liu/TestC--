#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    public:
        Student();
        Student(const string &name,
                int age,
                int score);
        const string &getName() const; 
        Student &setName(const string &name);

        int getAge() const;
        Student &setAge(int age);

        int getScore() const;
        Student &setScore(int score);

        const Student &print() const;
        Student &print();
            
    private:
        string name_;
        int age_;
        int score_;
};

Student::Student() 
    :name_(""), age_(-1), score_(-1)
{
}

Student::Student(const string &name,
                int age,
                int score)
    :name_(name), age_(age), score_(score)
{
}


const string &Student::getName() const{
    return name_;
} 
Student &Student::setName(const string &name){
    name_ = name;
    return *this;
}

int Student::getAge() const{
    return age_;
}
Student &Student::setAge(int age){
    age_ = age;
    return *this;
}

int Student::getScore() const{
    return score_;
}
Student &Student::setScore(int score){
    score_ = score;
    return *this;
}

const Student &Student::print() const{
    cout << "name = "  << name_ << " age = " << age_ 
        << " score = " << score_ << endl;
    return *this;
}

Student &Student::print() {
    cout << "name = "  << name_ << " age = " << age_ 
        << " score = " << score_ << endl;
    return *this;
}



int main(int argc, const char *argv[])
{
    Student s;
    s.print().setName("zhangsan").print().setAge(12).print().
        setScore(99).print();
    return 0;
}
