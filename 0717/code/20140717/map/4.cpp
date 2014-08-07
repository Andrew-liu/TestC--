#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


/**
 * 这里的Animal没有提供比较规则，所以不能作为map的key
 */
struct Animal{
};

int main(int argc, const char *argv[])
{
    Animal a;
    map<int, Animal> m;
    m[1] = a;
}
