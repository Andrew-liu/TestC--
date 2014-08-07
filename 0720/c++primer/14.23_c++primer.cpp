#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class Checkedptr
{
    friend Checkedptr operator + (const Checkedptr &, const size_t);
    friend Checkedptr operator - (const Checkedptr &, const size_t);
    friend bool operator == (const Checkedptr &, const Checkedptr &);
    friend bool operator != (const Checkedptr &, const Checkedptr &);
    friend bool operator > (const Checkedptr &, const Checkedptr &);
    friend bool operator >= (const Checkedptr &, const Checkedptr &);
    friend bool operator < (const Checkedptr &, const Checkedptr &);
    friend bool operator <= (const Checkedptr &, const Checkedptr &);
    public:
        Checkedptr(int *d, int *e);
        int &operator [] (size_t index);// 使用无符号数,防止下标越界
        int &operator * ();
    private:
        int *beg;
        int *end;
        int *curr;//指向当前元素,初始指向头部
};

int &Checkedptr::operator [] (size_t index)//判断是否越界
{
    if(beg+index == end)
    {
        throw out_of_range("[]");
    }
    return *(beg+index);
}
int &Checkedptr::operator *()
{
    if(curr == end)
    {
        throw out_of_range("*");
    }
    return *curr;
}
Checkedptr operator + (const Checkedptr &obj, const size_t index)
{
    Checkedptr ret(obj);
    if(ret.curr + index == ret.end)
    {
        throw out_of_range("+");
    }
    ret.curr = ret.curr + index;
    return ret;
}
Checkedptr operator - (const Checkedptr &obj, const size_t index)
{
    Checkedptr ret(obj);
    if(ret.curr - index < ret.beg)
    {
        throw out_of_range("-");
    }
    ret.curr = ret.curr - index;
    return ret;
}
bool operator == (const Checkedptr &obj1, const Checkedptr &obj2)
{
    return obj1.beg == obj2.beg && obj1.end == obj2.end && obj1.curr == obj2.curr;
}
bool operator != (const Checkedptr &obj1, const Checkedptr &obj2)
{
    return !(obj1 == obj2);
}
bool operator < (const Checkedptr &obj1, const Checkedptr &obj2)
{
    return obj1.beg == obj2.beg && obj1.end == obj2.end && obj1.curr < obj2.curr;
}
bool operator > (const Checkedptr &obj1, const Checkedptr &obj2)
{
    return obj1.beg == obj2.beg && obj1.end == obj2.end && obj1.curr > obj2.curr;
}
bool operator <= (const Checkedptr &obj1, const Checkedptr &obj2)
{
    return !(obj1 > obj2);
}
bool operator >= (const Checkedptr &obj1, const Checkedptr &obj2)
{
    return !(obj1 < obj2);
}


