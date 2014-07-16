#include <iostream>
#include <string>
#include <vector>
using namespace std;


class All
{
    private:
        static int  sum;//要有变量类型
    public:
        All()
        {
            sum++;
        }
        ~All()
        {
            --sum;
        }
        void show()
        {
            cout<<"sum = "<<sum <<endl;
        }
};

int All::sum=0;//放在类后
size_t count_calls()
{
    static size_t ctr=0;
    return ++ctr;
}
int main(int argc, const char *argv[])
{
  /*  
    All p1,p2,p3;
    p1.show();
    p2.show();
    p3.show();
    */
    for(int i=0;i<10;++i)
    {
        cout<<count_calls()<<" ";
    }
    cout<<endl;
    return 0;
}
