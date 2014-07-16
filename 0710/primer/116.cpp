#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    const char ca[]={'h','e','l','l','o'};//长度为5
    const char *str=ca;
    while(*str)
    {
        cout<< *str <<endl;
        str++;
    }
    return 0;

}
