#include <iostream>
#include <string>
#include <functional>
using namespace std;

void test(int i, double d, const string &s)
{
    cout << "i = " << i << " d = " << d << " s = " << s << endl;
}



int main(int argc, const char *argv[])
{
    //void(*)(int, double, const string&)

    //1.void (*)(int, double)
    function<void (int, double)> fp;
    string s = "foobar";
    fp = bind(&test,
              std::placeholders::_1,
              std::placeholders::_2,
              s);
    fp(100, 3.456);
    //2.void (*)(double, int, const string &)
    function<void (double, int, const string &)> fp2;
    fp2 = bind(&test,
               std::placeholders::_2, //int
               std::placeholders::_1,   //double
               std::placeholders::_3);  //string
    fp2(3.1415926, 23456, "foobar");

    //3.void (*)(const string &, int)

    //4. void (*) (const string &, int, double)
    
    //5. void (*)(int)

    //5.5 void(*)(const string &)

    //6. void (*)()


    return 0;
}
