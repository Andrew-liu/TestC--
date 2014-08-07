#include "WordCount.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    SuQing::WordCount wc("word.txt");
    string word;
    while(cin >> word)
    {
        wc.add(word);
    }

    wc.print();
    return 0;
}
