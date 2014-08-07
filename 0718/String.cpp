#include "String.h"
using namespace std;

String::String():str_(new char[1])
{
    str_[0] = '\0';
}

String::String(const char *s):str_(new char[strlen(s)+1])
{
    strcpy(str_, s);
}

String::String(const String &s):str_(new char[strlen(s.str_)+1])
{
    strcpy(str_, s.str_);
}

String::~String()
{
    delete [] str_;
}

String &String::operator = (const String &s)
{
    if(this != &s)
    {
        delete [] str_;
        str_ = new char[strlen(s.str_)+1];
        strcpy(str_, s.str_);
    }
    return *this;
}

void String::debug()
{
   cout << str_ << endl;
}

size_t String::size()
{
    return strlen(str_);
}


//考虑赋值的时候空间不足的问题
//先申请内存空间存放拼接后的字符串的结果
//
//
String &String::operator += (const char *s)
{
    return operator +=(s);
}
String &String::operator += (const String &s)
{
    char *pt = new char[::strlen(str_) + ::strlen(s.str_) + 1];
    ::strcpy(pt, str_);
    ::strcat(pt, s.str_);

    delete str_;
    str_ = pt;

    return *this;
}

inline ostream &operator << (ostream &out, const String &other)
{
    return out << other.str_;
}
inline istream &operator >> (istream &in, String &other)
{
    char buf[1024];
    cin >> buf;
    if(in)
    {
        other = buf; //用到赋值运算符
    }
    return in;
}
//加法不改变原来的对象
String operator + (const String &s1,const String &s2)
{
    String ret(s1);
    ret += s2;
    return ret;
}
String operator + (const String &s1, const char *s2)
{
    return s1 + String(s2);
}
String operator + (const char *s1, const String &s2)
{
    return String(s1) + s2;
}
bool operator < (const String &s1, const String &s2)
{
    return ::strcmp(s1.str_, s2.str_) < 0;
}
bool operator > (const String &s1, const String &s2)
{
    return s2 < s1;
}

bool operator <= (const String &s1, const String &s2)
{
    return !(s1 > s2);
}

bool operator >= (const String &s1, const String &s2)
{
    return  !(s1 < s2);
}
bool operator == (const String &s1, const String &s2)
{
    return (::strcmp(s1.str_, s2.str_) == 0);
}

bool operator !=(const String &s1,const String &s2)
{
    return !(s1 == s2);
}
int main(int argc, const char *argv[])
{
    String s("hello");
    String s2("world");
    cout << s + s2 << endl;
    cout << (s < s2) <<endl;

    cout << (s == s2) << endl;
    //is.debug();
    //String s1;
    //s1 = s;
    //s1.debug();
    return 0;
}




