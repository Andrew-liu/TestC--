#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

ifstream &read_file(ifstream &in,vector<string> &vec)
{
    string line;
    while(getline(in,line))
    {
        vec.push_back(line);
    }
    in.close();
}
void open_file(ifstream &in)
{
    in.close();
    in.clear();
    in.open("The_Holy_Bible.txt");
}
void read_word(vector<string> vec)
{
    string s;
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
//          istringstream str(*it);
          ostringstream str;
          str<<*it;
           /*
           while(str>>s)

           {
            cout<<s<<endl
           }
           */
          
            
    }
}
int main(int argc, const char *argv[])
{
    vector<string> vec;
    ifstream in("The_Holy_Bible.txt");//绑定了
    //open_file(in);
    read_file(in,vec);
    read_word(vec);

    return 0;
}
