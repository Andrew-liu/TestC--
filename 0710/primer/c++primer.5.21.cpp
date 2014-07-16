#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int x;
    vector<int> vec;
    while(cin>>x)
    {
        vec.push_back(x);
       }
    for(vector<int>::iterator ix=vec.begin();ix!=vec.end();++ix)
    {
        if(*ix%2!=0)
        {
            (*ix)*=2;
        }
    }
    for(vector<int>::iterator ix=vec.begin();ix!=vec.end();++ix)
    {
        cout<<*ix<<endl;
     }
    return 0;
}
