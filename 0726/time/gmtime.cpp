#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
using namespace std;

int main(int argc, const char *argv[])
{
    time_t t = time(NULL);
    
    struct tm *fuck = gmtime(&t);
    printf("%3d, %3d, %3d, %3d, %3d, %3d\n", 
            1900 + fuck->tm_year, 
            1 + fuck->tm_mon, 
            fuck->tm_mday,
            8 + fuck->tm_hour,
            fuck->tm_min,
            fuck->tm_sec);
    return 0;
}
