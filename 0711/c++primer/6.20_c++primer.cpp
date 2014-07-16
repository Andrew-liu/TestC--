#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Word
{
    string word;
    int cnt;
};
int main(int argc, const char *argv[])
{
    vector<Word> all;
    string s;
    int flag=0;
    while(cin>>s && !s.empty())
    {

        vector<Word>::iterator it;
        if(isupper(s[0]))
        {
            for(it=all.begin();it!=all.end();++it)
            {
                if(it->word==s)
                {
                    flag=1;
                    cout<<"repeat:"<<s<<endl;
                    break;//结束内循环
                }
            }
        }
        else
        {
            continue;
        }
        if(it==all.end())
        {
            Word single;
            single.word=s;
            single.cnt=1;
            all.push_back(single);
        }
        else
        {
            break;//因为有相同单词而结束
        }
    }
    if(flag==0)//表示没有重复
    {
        for(vector<Word>::iterator ix=all.begin();ix!=all.end();++ix )
        {
            cout<< ix->word<<" ";
        }
        cout<<endl;
    }

    return 0;
}
