#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Animal
{
    public:
        virtual void display()
        {
            cout << "Animal" << endl;
        }
};
class Cat : public Animal
{
    public:
        void display()
        {
            cout << "Cat" << endl;
        }
};
int main(int argc, const char *argv[])
{
    Cat c1;
    Animal *a = &c1;
    a->display();
    return 0;
}
