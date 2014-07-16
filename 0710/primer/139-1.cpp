#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc, const char *argv[])
{
    char str1[100];
    char str2[50];
    gets(str1);
    gets(str2);
    strcat(str1,str2);
    printf("%s\n",str1);
    string s1,s2;
    cin>>s1>>s2;
    s1+=s2;
    cout<<s1<<endl;
    return 0;
}
