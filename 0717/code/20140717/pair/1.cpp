#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, const char *argv[])
{
    pair<string, int> p1;
    p1.first = "beijing";
    p1.second = 35;

    pair<string, int> p2("shanghai", 34);

    pair<string, string> p3 = make_pair(string("shenzhne"), string("nanshan"));


    return 0;
}
