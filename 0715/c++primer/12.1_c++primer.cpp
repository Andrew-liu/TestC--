#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
    public:
        Person();
        Person(const string &name,const string &address);
        ~Person();
        string get_name() const
        {
            return name_; 
        }
        string get_address() const
        {
            return address_;
        }
        void show()
        {
            cout << "name =" << name_ << endl;
            cout << "address =" << address_ << endl;
        }
    private:
        string name_;
        string address_;
};
Person::Person(const string &name, const string &address):name_(name),address_(address)
{
}
Person::~Person()
{
}

int main(int argc, const char *argv[])
{
    Person pre("liubin","602");
    pre.show();
    return 0;
}
