#include "10.3.9_c++primer.h"
Word::Word():rfile_("1.txt"),cfile_("2.txt")
{}
Word::~Word()
{}

void Word::open_file()
{
    rpair_.close();
    cpair_.close();
    rpair_.clear();
    cpair_.clear();
    rpair_.open(rfile_.c_str());
    cpair_.open(cfile_.c_str());
}

void Word::read_pair()
{
    string first,last;
    while(rpair_ >> first >> last, !rpair_.eof())
    {
        map_.insert(make_pair(first, last));
    }
}

void Word::output()
{
    string s;
    while(cpair_ >> s, !cpair_.eof())
    {
       map<string, string>::iterator ret =map_.find(s);
       if(ret != map_.end())
       {
            cout << ret->second << " " << flush;
       }
       else
       {
            cout << s << " " << flush;
       }
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    Word pre;
    pre.open_file();
    pre.read_pair();
    pre.output();
    return 0;
    return 0;
}
