#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Check
{

    public:
        Check(int a)
        {
            this->a = a;
        }
        Check &operator ++ ();
        Check &operator -- ();
        Check operator ++ (int);//用来区分前++还是后++
        Check operator -- (int);
    private:
        int a;
};

Check &Check::operator ++ ()
{
    if(curr == end)
    {
        throw run_of _range("wrong");
    }
    ++curr;
    return *this;
}
Check &Check::operator -- ()
{
    if(curr == begin)
    {
        throw run_of_range("wrong");
    }
    --curr;
    return *this;
}

Check Check::operator ++ (int) //后++
{
    Check ret(*this);//指针要定义复制构造函数
    ++(*this);
    return ret;
}
Check Check::operator -- (int)
{
    Check ret(*this);
    --(*this);
    return ret;
}

int main(int argc, const char *argv[])
{
    A test(1);
    return 0;
}

