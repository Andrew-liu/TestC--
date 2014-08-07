#ifndef WORD_COUNT_H_
#define WORD_COUNT_H_ 

#include <string>
#include <map>
#include <set>

namespace SuQing
{
class WordCount
{
    public:
        WordCount(const std::string &filename);
        void add(const std::string &word);
        void print() const;

    private:
        void readExclude();

        std::map<std::string, int> words_;
        std::set<std::string> exclude_;
        std::string excludeFileName_;
};

}

#endif  /*WORD_COUNT_H_*/
