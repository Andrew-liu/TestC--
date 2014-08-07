#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define MAXSIZE 1005
int memo[MAXSIZE][MAXSIZE];
//i j 表示要比较字符的个数  从1开始
int Lcs(const string &A, const string &B, int i, int j)
{
    if(i == 0 || j == 0)
        return 0;
    if(memo[i][j] != -1)
    {
        return memo[i][j];
    }
    //A[i] B[j]
    if(A[i-1] == B[j-1])
    {
        memo[i][j] = Lcs(A, B, i-1, j-1)+1;
        return memo[i][j];
    }
    else
    {
        int t1 = Lcs(A, B, i-1, j);
        int t2 = Lcs(A, B, i, j-1);
        memo[i][j] = (t1 >= t2 ? t1 : t2);
        return memo[i][j];
    }
}


int NonLcs(const string &A, const string &B)
{
//从1开始,主要是为了构造一个虚拟边界,第0行和第0列作为边界,两个字母的比较从第一行和第一列开始, 
    for(int i = 1; i <= A.size(); ++i)
    {
        for(int j = 1; j <= B.size(); ++j)
        {
            if(A[i-1] == B[j-1])//对于两个字符串的字符比较应该从0开始,所以-1
            {
                memo[i][j] = memo[i-1][j-1]+1;//memo起到缓存作用,减少重复计算
            }
            else
            {
                memo[i][j] = (memo[i-1][j] >= memo[i][j-1] ? memo[i-1][j] : memo[i][j-1]);
            }
        }
    }
}


int main(int argc, const char *argv[])
{
    string s1 = argv[1];
    string s2 = argv[2];
    memset(memo, 0, sizeof memo);
//    int ret = Lcs(s1, s2, s1.size(), s2.size());
    NonLcs(s1, s2);
    cout << memo[s1.size()][s2.size()] << endl;
    return 0;
}
