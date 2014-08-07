#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal
{
    public:
        void display()
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
    pa->display();   // Animal

    pa = &d;
    pa->display(); // Animal


    return 0;
}


