#include "thread.h"
#include <iostream>

using namespace std;

void print()
{
    cout << "I am a best one!" << endl;
}

void test(int i, const string &s)
{
    cout << i << " " << s << endl;
}

class Test
{
    public:
        void test1()
        {
            cout << "never " << endl;
        }
        void test2()
        {
            cout << "never give us" << endl;
        }
};

class Factory
{
    public:
        Factory():thread_(bind(&Factory::start, this))
        {}
        void start()
        {
            cout << "class " << endl;
        }
        void join()
        {
            thread_.join();
        }
    private:
        Thread thread_;
};

int main(int argc, const char *argv[])
{
    Thread T(print);
    T.start();
    T.join();

    Thread T1(bind(&test, 12, "hello"));
    T1.start();
    T1.join();

    Test ttt;
    Thread T2(bind(&Test::test1, &ttt));
    T2.start();
    T2.join();

    Test tt1;
    Thread T3(bind(&Test::test2, &tt1));
    T3.start();
    T3.join();

    Factory  F;
    F.start();
    F.join();
    return 0;
}


