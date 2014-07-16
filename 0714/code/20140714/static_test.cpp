#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal{
    public:
        Animal()
        {
            ++sum;
        }

        ~Animal()
        {
            --sum;
        }

        static void printSum()
        {
            cout << "sum = " << sum << endl;
        }

    private:
        //这里是声明，而不是定义 
        static int sum;
        int a_;
};

int Animal::sum = 0;

int main(int argc, const char *argv[])
{
    /*Animal a1, a2;
    Animal::printSum();

    Animal a3, a4, a5;
    Animal::printSum();
    a5.printSum(); */

    Animal::printSum();
    return 0;
}

