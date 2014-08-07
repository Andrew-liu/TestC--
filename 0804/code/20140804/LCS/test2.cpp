#include <iostream>
#include <string>
#include <string.h>
using namespace std;

/*
 * i和j表示的是字符数量
 * 所以参数的含义是 A的前i个字符
 * B的前j个字符
 */

int memo[100][100];

int LongestCommonSubsequence(const string &A,
                             const string &B,
                             int i,
                             int j)
{
    if(i == 0 || j == 0)
        return 0;
    if(memo[i][j] != -1)  //如果计算过，直接返回备忘录的内容
        return memo[i][j];

    if(A[i-1] == B[j-1])
    {
        memo[i][j] = LongestCommonSubsequence(A, B, i-1, j-1) + 1;
        return memo[i][j];
    }else
    {
        int t1 = LongestCommonSubsequence(A, B, i-1, j);
        int t2 = LongestCommonSubsequence(A, B, i, j-1);
        memo[i][j] = t1 > t2 ? t1 : t2;
        return memo[i][j];
    }
}


int main(int argc, const char *argv[])
{
    string s1 = argv[1];
    string s2 = argv[2];
    memset(memo, -1, sizeof memo);
    cout << LongestCommonSubsequence(s1, s2, s1.size(), s2.size()) 
        << endl;
    return 0;
}
