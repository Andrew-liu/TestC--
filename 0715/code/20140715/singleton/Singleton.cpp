#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 1.把构造函数设为私有，外面无法直接生成对象
 * 2. 在类内部添加函数，生成对象，但是不可行
 * 3. 把该函数设为static
 * 4. 此时可以生成对象，但是不唯一
 */
class Singleton
{
    public:
        static Singleton *getInstance()
        {
            Singleton *ps = new Singleton;
            return ps;
        }
    private:
        Singleton(){}
};

int main(int argc, const char *argv[])
{
    //Singleton s; 
    Singleton *ps = Singleton::getInstance();
    cout << ps << endl;
    Singleton *ps2 = Singleton::getInstance();
    cout << ps2 << endl;
    return 0;
}

