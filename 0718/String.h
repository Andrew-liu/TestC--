#ifndef _STRING_
#define _STRING_
#include <iostream>
#include <stddef.h>
#include <string.h>

class String
{
    friend std::ostream &operator<< (std::ostream &, const String &);
    friend std::istream &operator>> (std::istream &, String &);

    friend String operator + (const String &, const String &);
    friend String operator + (const String &, const char *);
    friend String operator + (const char *, const String &);

    friend bool operator < (const String &, const String &);
    friend bool operator > (const String &, const String &);
    friend bool operator <= (const String &, const String &);
    friend bool operator >= (const String &, const String &);
    friend bool operator == (const String &, const String &);
    friend bool operator != (const String &, const String &);


    public:
        String();
        String(const char *s);
        String(const String &s);
        ~String();
        String &operator = (const String &s);
        
        String &operator +=(const char *);
        String &operator +=(const String &);
        void debug();
        std::size_t size();

    private:
        char *str_;

};

#endif
