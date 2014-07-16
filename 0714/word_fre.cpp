#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
struct  Node
{
    string word;
    int cnt;
};
int cmp(Node a, Node b)
{
    return a.cnt > b.cnt;
}
class Sta
{
    private:
        vector<Node> words_;
    public:
        void open_file(ifstream &in,const string &filename)//获取文件输入流
        {
            cout<<"ok"<<endl;
            in.close();
            in.clear();
            in.open(filename.c_str());
        }
        void read_word(ifstream &in)//构造顺序表
        {
            cout<<"ok2"<<endl;
            string single;
            while(in >> single,!in.eof())
            {
//                cout << single << endl;
                for(size_t i=0;i!=single.size();++i)
                {
                    if(isupper(single[i]))
                    {
                        single[i] = tolower(single[i]);
                    }
                }
                vector<Node>::iterator it;
                for(it = words_.begin(); it != words_.end(); ++it)
                {
                    if(it->word == single)
                    {
                        ++(it->cnt);
                        break;
                    }
                }
                if(it == words_.end())
                {
                    Node pre;
                    pre.word = single;
                    pre.cnt = 1;
                    words_.push_back(pre);
                    continue;
                }
            }
        }
        void sort_word()
        {
            sort(words_.begin(),words_.end(),cmp);         
        }
        void show_word()
        {
            for(int ix=0;ix!=10;++ix)
            {
                cout << words_[ix].word << " " <<words_[ix].cnt << endl;
            }
        }
};

int main(int argc, const char *argv[])
{
    Sta all;
    string name("The_Holy_Bible.txt");
    ifstream in;
    all.open_file(in,name);
    all.read_word(in);
    all.sort_word();
    all.show_word();
    return 0;
}
