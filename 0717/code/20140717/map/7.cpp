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

    pair<map<string, int>::iterator, bool> ret;
    ret = m.insert(make_pair("nanjing", 45));
    if(ret.second == true)
    {
        cout << "insert nanjing successfully!" << endl;
    }

    //此处insert失败
    ret = m.insert(make_pair("beijing", 40));
    if(ret.second == false)
    {
        cout << "insert beijing failed" << endl;
    }

    for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        // *it pair
        cout << "city :" <<  it->first << " tep : " << it->second << endl;
    }
    return 0;
}

