#include <iostream>
#include <string>
#include <vector>
 using namespace std;
 int main(int argc, const char *argv[])
 {
     string s;
     vector<string> str;
     while(cin>>s)
     {
        str.push_back(s);
     }
     for(vector<string>::iterator it=str.begin();it!=str.end();it++)
         cout<<*it<<" ";
     cout<<endl;
     return 0;
 }
