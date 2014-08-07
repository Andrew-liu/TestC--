#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Exmpl
{
    public:
        Exmpl()
        {
            cout << "Exmpl()" << endl;
        }
        Exmpl(const Exmpl &other)
        {
            cout << "Exmpl(const Exmpl &other)" << endl;
        }
        Exmpl &operator = (const Exmpl &other)
        {
            if(this != &other)
            {
                cout << "Exmpl &operator = (const Exmpl &other)" << endl;
            }
            return *this;
        }
        virtual ~Exmpl()
        {
            cout << "virtual ~Exmpl()" << endl;
        }

};
class NewEx : public Exmpl
{
    public:
        NewEx():Exmpl()
        {
            cout << "NewEx()" << endl;
        }
        NewEx(const NewEx &other) : Exmpl(other)
        {
            cout << "NewEx(const NewEx &other)" << endl;
        }
        NewEx &operator = (const NewEx &other)
        {
            if(this != &other)
            {
                Exmpl::operator = (other);
                cout << " NewEx &operator = (const NewEx &other)" << endl;
            }
            return *this;
        }
        ~NewEx()
        {
            cout << "~NewEx()" << endl;
        }
    private:
        Exmpl ex;
};
int main(int argc, const char *argv[])
{
    Exmpl ex;
  //  Exmpl ex1(ex);// 调用赋值构造复制构造函数
  //  ex1 = ex; //对已存在的函数 = 调用赋值操作符 ,对于新创建对象会用复制构造函数
    NewEx ne;//调用三次父类构造函数(构造父类.构造子类对象,初始化调用父类初始化函数)以及自己的初始化函数,反顺序析构
    NewEx ne1(ne);//调用父类复制构造函数,形成新的临时父类对象,调用子类复制构造函数
    ne1 = ne; //父类赋值操作符,子类的复制操作符
    return 0;
}
