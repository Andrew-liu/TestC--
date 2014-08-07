#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NoName
{
    public:
        NoName(): pstring(new std::string), i(0), d(0)
        {
        }
        NoName(const NoName &obj):
            pstring(new string(*(obj.pstring))),
            i(obj.i),
            d(obj.d)
        {
        }
        ~NoName()
        {
            delete pstring;
        }
        NoName &operator = (const NoName &obj)
        {
            pstring = new string(*(obj.pstring));
            i = obj.i;
            d = obj.d;
            return *this;
        }

    private:
        std::string *pstring;
        int    i;
        double d;
};


int main(int argc, const char *argv[])
{
    NoName  first;
    NoName second = first; 
    return 0;
}
