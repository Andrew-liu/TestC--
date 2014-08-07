#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char *argv[])
{
    map<string, int> words;

    string word;
    pair<map<string, int>::iterator, bool> ret;
    while(cin >> word)
    {
        //words[word]++;
        ret = words.insert(make_pair(word, 1));
        if(ret.second == false) /* 该单词已经存在 */
        {
            //ret.first 指向该单词的迭代器
            //ret.first->second  代表该单词的次数
            ++ret.first->second;
        }
    }


    for(map<string, int>::iterator it = words.begin(); it != words.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl; 
    }


    return 0;
}

