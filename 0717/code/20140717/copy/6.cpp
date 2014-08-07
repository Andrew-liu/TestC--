#include <iostream>
#include <string.h>
using namespace std;


class String
{
    public:
        String();
        String(const char *str);
        String(const String &other);
        ~String();
        String &operator=(const String &other);
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

String::String(const String &other)
    :str_(new char[strlen(other.str_) + 1])
{
    strcpy(str_, other.str_);
}

String &String::operator=(const String &other)
{
    delete[] str_;
    str_ = new char[strlen(other.str_) + 1];
    strcpy(str_, other.str_);

    return *this;
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
/*
    String s2;
    s2 = s;
    s2.debug();
*/
    s = s;
    s.debug();
    return 0;
}



