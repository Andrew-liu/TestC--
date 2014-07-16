#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    /*
    int i=0;
    string s;
    vector<string> arr;
    vector<string *> str;
    while(cin>>s)
    {
        
        arr.push_back(s);
        str.push_back(&arr[i++]);
    }

    for(vector<string *>::iterator it=str.begin();it!=str.end();++it)
    {
        cout<<*it<<" ";
    }
    for(vector<string>::iterator ix=arr.begin();ix!=arr.end();++ix)
    {
        cout<<*ix<<" "<<(*ix).size()<<endl;
    }
    cout<<endl;
    */

    int x,y;
    
    cout<<"input two number :"<<endl;
    cin >>x>>y;
    if(x>=y)
    {
        cout<<"max="<<x<<endl;
    }
    else
    {
        cout<<"max= "<<y<<endl;
    }
    return 0;
}
