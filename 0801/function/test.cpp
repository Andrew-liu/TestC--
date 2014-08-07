#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

void test(int i, double d, const string &s)
{
    cout << "i = " << i << ", d = " << d << ", s =" << s << endl;
}

int main(int argc, const char *argv[])
{
    //void (*)(int, double)
    function<void (int, double)> fp;
    string s = "foobar";
    fp = bind(&test,
              std::placeholders::_1,
              std::placeholders::_2,
              s);
    fp(100, 3.45);

    //void (*)(double, int, const string &)
    function<void (double, int, const string &)> fp2;
    fp2 = bind(&test, 
               std::placeholders::_2,
               std::placeholders::_1,
               std::placeholders::_3);
    fp2(2.34, 2323, "string");

    //void (*)(const string &, int)
    double di = 3.45;
    function<void (const string &, int)> fp3;
    fp3 = bind(&test,
               std::placeholders::_2,
               di,
               std::placeholders::_1);
    fp3("foobar", 345);

    //void (*)(const string &, int,double)
    function<void (const string &, int, double)> fp4;
    fp4 = bind(&test,
               std::placeholders::_2,
               std::placeholders::_3,
               std::placeholders::_1);
    fp4("foobar", 123, 4.56);

    //void (*)(int)
    function<void (int)> fp5;
    string s1= "hello";
    double di1= 3.4;
    fp5 = bind(&test,
               std::placeholders::_1,
               di1,
               s);
    fp5(100);

    //void (*)(const string &)
    function<void (const string &)> fp6;
    int ii =10;
    double di2 = 3.56;
    fp6 = bind(&test,
               ii,
               di2,
               std::placeholders::_1);
    fp6("world");

    //void (*)()
    int ii2 = 1000;
    double di4 = 1.242436;
    string s3 = "hello world, i am coming";
    function<void (void)> fp7;
    fp7 = bind(&test,
               ii2,
               di4,
               s3);
    fp7();
    return 0;
}
