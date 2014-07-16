#include <iostream>
#include <string>
#include <vector>
#include "Thread.h"
using namespace std;

int main(int argc, const char *argv[])
{
    Thread t;
    t.start();

    t.join();
    return 0;
}
