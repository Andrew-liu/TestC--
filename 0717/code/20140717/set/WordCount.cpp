#include "WordCount.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace SuQing;
using namespace std;

WordCount::WordCount(const string &filename)
    :excludeFileName_(filename)
{
    readExclude();
}

void WordCount::readExclude()
{
    fstream infile;
    infile.open(excludeFileName_.c_str());
    if(!infile)
    {
        throw runtime_error("open excludeFile failed");
    }

    string word;
    while(infile >> word)
    {
        exclude_.insert(word);
    }

    infile.close();
}


void WordCount::add(const std::string &word)
{
    if(exclude_.count(word) == 0)
    {
        words_[word]++;
    }
}
void WordCount::print() const
{
    for(map<string, int>::const_iterator it = words_.begin(); 
            it != words_.end(); ++it)
    {
        cout << it->first << " occurs " << it->second << " times" << endl;
    }
}



