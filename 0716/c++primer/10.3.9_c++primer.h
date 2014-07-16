#ifndef _WORD_
#define _WORD_
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;
class Word
{
    public:
        Word();
        ~Word();
        void open_file();
        void read_pair();
        void output();
    private:
        map<string, string> map_;
        ifstream rpair_;//读pair取用
        ifstream cpair_;//读转换文本用
        std::string rfile_;
        std::string cfile_;
};
#endif
