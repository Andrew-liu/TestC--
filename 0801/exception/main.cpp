#include "Exception.h"
#include <stdio.h>
using namespace std;

void foo()
{
    throw Exception("foobar");
}

void fun()
{
    foo();
}

int main(int argc, const char *argv[])
{
    try{
        foo();
    }
    catch(Exception &ex)
    {
        printf("reason: %s\n", ex.what());
        printf("stack trace: %s\n", ex.stackTrace());
    }
    return 0; 
    return 0;
}
