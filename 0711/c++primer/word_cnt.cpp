#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Word
{
    string word;
    int cnt;
}Word;
void input_word(vector<Word> &count)
{
    string s;
    while(cin>>s)
    {
       vector<Word>::iterator it;
       for(it=count.begin();it!=count.end();++it)
       {
            if(it->word==s)
            {
                ++it->cnt;
            }
       }
       if(it==count.end())
       {
           Word single;
           single.word=s;
           single.cnt=1;
           count.push_back(single);
       }
    }
}
void max_word(vector<Word> &count)
{
    int max=0;
    for(vector<Word>::iterator it=count.begin();it!=count.end();++it)
    {
        if(it->cnt > max)
        {
            max=it->cnt;
        }
    }
    cout<<"max=" <<max<<endl;
}

int main(int argc, const char *argv[])
{

    vector<Word> count;//空
    input_word(count);//初始化
    max_word(count);//输出最大值
    return 0;
}
