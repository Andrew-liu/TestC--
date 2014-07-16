#include <iostream>
#include <string>
#include <vector>
using namespace std;
class X
{
    friend class Y;
    friend void print(const X &x);//const的X类变量
    
    private:
        int x_;
        int y_;
};
class Y
{
    public:
        void print(const X &)//名字和形参相同
        {
            cout <<x.x_<<endl;
            cout<<x.y_:<<endl;
        }
};

void 


int main(int argc, const char *argv[])
{
    

    return 0;
}
