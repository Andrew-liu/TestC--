#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
    private:
        string name_;
        int age_;
        int id_;
    public:
        Student():name_(),age_(),id_(){}
        Student(const string &s,int i,int j)
        {
            name_=s;
            age_=i;
            id_=j;
        }
        ~Student(){};
        Student &set(const string &s,const int &age,const int &id)
        {
            this->name_=s;
            this->age_=age;
            this->id_=id;
            return *this;
        }
        void show(ostream &os)
        {
            os<<name_<<" "<<age_<<" "<<id_<<endl;
        }
        int get_age() const
        {
            return age_;
        }
        Student &set_age(int age)
        {
            age_=age;
            return *this;
        }

};
int main(int argc, const char *argv[])
{
    Student p1("suqing",18,1);
  //  p1.set("suqing",18,1);
    const Student p2;
    p2.get_age();
//    p2.set_age(12);
//    p1.show(cout);
    p1.set("liubin",100,2).set_age(22).show(cout);
    return 0;

}
