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

};


int main(int argc, const char *argv[])
{
    Animal a;
    return 0;
}
