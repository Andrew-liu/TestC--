#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAXSIZE 100
using namespace std;

int memo[MAXSIZE][MAXSIZE];

int edit(const string &s1, const string &s2)
{
    memset(memo, 0, sizeof(memo));
    int x = s1.size();
    int y = s2.size();
    //初始化
    for(int i = 1; i <= x; ++i)
    {
        memo[i][0] = i;
    }
    for(int j = 1; j <= y; ++j)
    {
        memo[0][j] = j;
    }
    for(int i = 1; i <= x; ++i)
    {
        for(int j = 1; j <= y; ++j)
        {
            int inserts = memo[i][j-1] + 1;
            int deletes = memo[i-1][j] + 1;
            int replace;
            if(s1[i-1] == s2[j-1])
                replace = memo[i-1][j-1];
            else
                replace = memo[i-1][j-1] + 1;
            memo[i][j] = min(min(inserts, deletes), replace);
        }
    }
    return memo[x][y];
}

int main(int argc, const char *argv[])
{
    int ret = edit(argv[1], argv[2]);
    cout << ret << endl;
    return 0;
}

