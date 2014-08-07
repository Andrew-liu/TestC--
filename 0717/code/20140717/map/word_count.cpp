#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char *argv[])
{
    map<string, int> words;

    string word;
    while(cin >> word)
    {
        //已经存在的
        //map[word]++;
        //不存在
        //map[word] = 1;
        words[word]++;
    }


    for(map<string, int>::iterator it = words.begin(); it != words.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl; 
    }


    return 0;
}

