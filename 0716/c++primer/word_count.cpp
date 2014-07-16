#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;
void open_file(ifstream &in,const string filename)
{
    in.close();
    in.clear();
    in.open(filename.c_str());
}

int main(int argc, const char *argv[])
{
    string name = "The_Holy_Bible.txt";
    ifstream in;
    open_file(in, name);
    string word;
    map<string, int> word_count;
    while(in>>word,!in.eof())
    {
       // ++word_count[word];
       pair<map<string, int>::iterator, bool> ret = word_count.insert(map<string, int>::value_type(word, 1));
       if(ret.second == false) //表示已存在
       {
        ++ret.first->second;
       }
    }
//    sort(word_count.begin(), word_count.end());
/*
    for(map<string, int>::iterator it = word_count.begin(); it != word_count.end(); ++it)
    {
        cout << it->first << it->second << endl;    
    }
    cout << word_count.count("yourselves") << endl;   
    */
    map<int, string> cnt;
    for(map<int, string>::iterator it = cnt.begin(); it != cnt.end();++it)
    {
        cnt.insert(map<int, string>::value_type(it->second, it->first));
    }
    for(map<int, string>::iterator it = cnt.begin(); it != cnt.end(); ++it)
    {
        cout << it->first << it->second << endl;    
    }
    return 0;
}
