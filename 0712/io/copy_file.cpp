#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, const char *argv[])
{
    ifstream in;
    ofstream out;
    in.open("in.txt");
    out.open("out.txt");
    string s;
    while(getline(in,s))
    {
        out<<s<<endl;
    }
    in.close();
    out.close();
    return 0;
}
