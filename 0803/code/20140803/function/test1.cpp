#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;

void test(int i, double d, const string &s)
{
    cout << i << " " << d << " " << s << endl;
}

int main(int argc, const char *argv[])
{
    
    // void (int, double, string)


    //3.void (*)(const string &, int))
    function<void (const string&, int)> fp;
    fp = bind(&test,
               _2,         //int
               3.1415,         //double
               _1);         //const string &
    fp("foobar", 34);  //_1, _2

    //4. void (*) (const string &, int, double)
    function<void (const string &, int, double)> fp2;
    fp2 = bind(&test, _2, _3, _1);  //bind参数的顺序一定是int double string

    fp2("foobar", 98, 3.14);


//5. void (*)(int)

    function<void (int)> fp3 = bind(&test, _1, 3.14, "foobar");
    fp3(23);

//    //5.5 void(*)(const string &)
    
    function<void (const string &)> fp4 = bind(&test, 12, 3.14, _1);
    fp4("foobar");


//        //6. void (*)())

    function<void ()> fp5 = bind(&test, 12, 3.14, "foobar");
    fp5();










    return 0;
}







