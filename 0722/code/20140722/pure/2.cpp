#include <iostream>
#include <string>
#include <vector>
using namespace std;

//这个类叫做抽象类
class Animal
{
    public:
        //纯虚函数
        virtual void run() = 0;
        virtual ~Animal() {}
};

class Cat : public Animal
{
    public:
        void run()
        {
            cout << "Cat " << endl;
        }
};

int main(int argc, const char *argv[])
{
    Animal *pa = new Cat;

    pa->run();
    delete pa;
    return 0;
}
