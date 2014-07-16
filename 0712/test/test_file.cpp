#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
using namespace std;
ifstream &open_file(const string &filename,ifstream &is)
{
    is.close();
    is.clear();
    is.open(filename.c_str());
    return is;
}

ifstream &read_file(const string &filename,ifstream &is,istringstream &iss,vector<string> &lines,vector<string> &words)
{
    if(!open_file(filename,is))
    {
        throw runtime_error("open failed!");
    }
    string line,word;
    while(getline(is,line))
    {
        lines.push_back(line);
        iss.str(line);//str
        while(iss>>word)
        {
            words.push_back(word);
        }
     //每次使用完字符串流 清除一下   
     iss.clear();
     }
    is.close();
    is.clear();//顺序?
    return is;

}

int main(int argc, const char *argv[])
{
    

    return 0;
}
