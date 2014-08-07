#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, const char *argv[])
{
    map<string, int> m;

    m["beijing"] = 33;
    m["tianjin"] = 34;
    m["shenzhen"] = 30;
    m["longhua"] = 40;

    m["beijing"] = 35;


    cout << m.size() << endl;

    cout << m["longhua"] << endl;
    cout << m["beijing"] << endl;

    return 0;
}

