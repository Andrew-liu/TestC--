#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


uint64_t memo[1000];
// 1 2 3 5 8 13
uint32_t g_count = 0;
uint64_t fab(uint32_t n)
{
    g_count++;
    if(n == 0 || n == 1)
        return 1;
    else
    {
        if(memo[n] != -1)
            return memo[n];
        else
        {
            memo[n] = fab(n-1) + fab(n-2);
            return memo[n];
        }
    }
}


int main(int argc, const char *argv[])
{
    memset(memo, -1, sizeof memo);
    cout << fab(atoi(argv[1])) << endl;
    cout << g_count << endl;
    return 0;
}

