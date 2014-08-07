#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Exmpl
{
    public:
        Exmpl() //默认
        {
            std::cout << "Exmpl()" << std::endl;     
        }
        Exmpl(const Exmpl &other) //复制构造函数
        {
            std::cout << "Exmpl(const Exmpl &other)" << std::endl;
        }
        Exmpl &operator = (const Exmpl &other) //赋值运算符
        {
            std::cout << "Exmpl &operator = " << std::endl;
            return *this;
        }
        ~Exmpl()
        {
            std::cout << "~Exmple() " << std::endl;
        }
        void func1(Exmpl obj)//对象
        {}
        void func2(Exmpl &obj)//对象的引用
        {}
        Exmpl func3()
        {
            Exmpl obj;
            return obj;//返回
        }
};

int main(int argc, const char *argv[])
{
    Exmpl obj; //调用无参构造函数和析构函数
    obj.func1(obj); //进行值传递,调用复制构造函数最后销毁形参的副本
    obj.func2(obj); //引用传参给对象起了个别名,不会创建副本
   obj = obj.func3();//函数局部作用域内初始化一个成员,调用赋值操作符,销毁返回值副本,
    Exmpl *p = new Exmpl; //动态创建对象
    delete p; //释放动态分配空间
    return 0;
}
