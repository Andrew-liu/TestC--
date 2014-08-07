#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal
{
    public:
        virtual void display()
        {
            cout << "In Animal " << endl;
        }
};

class Cat : public Animal
{
    public:
        void display()
        {
            cout << "In Cat " << endl;
        }
};

class Dog : public Animal
{
    public:
        void display()
        {
            cout << "In Dog " << endl;
        }
};


int main(int argc, const char *argv[])
{
    Animal *pa;

    Cat c; 
    Dog d;

    pa = &c;
    pa->display();   // Cat 

    pa = &d;
    pa->display(); // Dog


    return 0;
}


