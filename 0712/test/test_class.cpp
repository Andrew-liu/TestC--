#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student 
{
    string name_;
    int age_;
    int id_;
    void print(ostream &os)
    {
        os<<"name="<<name_<<" age="<<age_<<" id="<<id_<<endl;
    }
};

int main(int argc, const char *argv[])
{

    Student p1;
    p1.name_="liubin";
    p1.age_=20;
    p1.id_=10086;
    p1.print(cout);
    Student *p2=new Student;
    p2->name_="suqing";
    p2->age_=28;
    p2->id_=10010;
    p2->print(cout);
    
    return 0;
}
