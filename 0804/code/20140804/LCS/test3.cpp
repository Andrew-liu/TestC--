#include <iostream>
#include <stdint.h>
#include <stdlib.h>
using namespace std;


// 1 2 3 5 8 13
uint32_t g_count = 0;
uint64_t fab(uint32_t n)
{
    g_count++;
    if(n == 0 || n == 1)
        return 1;
    else
    {
        return fab(n-1) + fab(n-2);
    }
}


int main(int argc, const char *argv[])
{
    cout << fab(atoi(argv[1])) << endl;
    cout << g_count << endl;
    return 0;
}

