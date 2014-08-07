#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

//void (*)()
void test()
{
    cout << "test ..." << endl;
}


class Test
{
    public:
        //void (*)()
        static void test_static()
        {
            cout << "test static ..." << endl;
        }

        //void (Test::*)()   // Test *
        void test2()
        {
            cout << "test2 ... In Test " << endl;
        }

        // void (Test::*)(int)
        void test3(int i)
        {
            cout << i << " test3 In Test .. " << endl;
        }

};



int main(int argc, const char *argv[])
{
    function<void ()> fp;
    fp = test;
    fp();

    fp = Test::test_static;
    fp();


    Test t;
    //void (*) (Test *)
    fp = bind(&Test::test2, &t);
    fp();

    //test3  void(*) (Test *, int)
    fp = bind(&Test::test3, &t, 1000);
    fp();


    //test3 -> void(*)(int)
    function<void (int)> fp2;
    fp2 = bind(&Test::test3, &t, std::placeholders::_1);
    fp2(10000);

    return 0;
}






