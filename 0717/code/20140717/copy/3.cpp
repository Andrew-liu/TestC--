#include <iostream>
#include <string.h>
using namespace std;


/*
 * String采用编译器默认的拷贝构造函数
 * 在复制时，仅仅复制了str的值
 * 复制后，两个string对象指向同一块内存
 * 对象析构的时候，该内存被delete两次
 *
 */

class String
{
    public:
        String();
        String(const char *str);
        ~String();
        void debug() const;

    private:
        char *str_;
};

String::String()
    :str_(new char[1])
{
    str_[0] = '\0';
}

String::String(const char *str)
    :str_(new char[strlen(str) + 1])
{
    strcpy(str_, str);
}

String::~String()
{
    delete[] str_;
}

void String::debug() const
{
    cout << str_ << endl;
}


int main(int argc, const char *argv[])
{
    String s("hello");
    s.debug();

    String s2(s);
    s2.debug();

    return 0;
}



