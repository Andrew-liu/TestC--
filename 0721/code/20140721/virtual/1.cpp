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
    Cat c;
    c.display(); // Cat

    Dog d;
    d.display(); // Dog
    return 0;
}


