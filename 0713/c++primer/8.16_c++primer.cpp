#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

ifstream &read_file(ifstream &in)
{
    string line;
    while(getline(in,line))
    {
        string s;
        istringstream stream(line);
        while(stream>>s)
        {
            cout<<s<<fflush;
        }
    }
    in.close();
}
void open_file(ifstream &in)
{
    in.close();
    in.clear();
    in.open("The_Holy_Bible.txt");
}
int main(int argc, const char *argv[])
{
    ifstream in("The_Holy_Bible.txt");
    //open_file(in);
    read_file(in);
    return 0;
}
