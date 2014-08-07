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


    map<string, int>::iterator it;
    string city;
    while(cin >> city){
        it = m.find(city);
        if(it == m.end()){
            cout << "failed!" << endl;
        }else{
            cout << city << " : " << m[city] << endl;
        }
    }

    return 0;
}

