#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc, const char *argv[])
{
    /*
    char str[20];
    scanf("%s",str);
    printf(" str = %s\n",str);
    
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    vector<int> vec;
    for(size_t ix=0;ix!=10;++ix)
    {
        vec.push_back(arr[ix]);
    }
    for(auto it=vec.begin();it!=vec.end();++it)
    {
        cout << *it << " ";
    }
    cout<<endl;
    */
    string s;
    vector<string> vec;
    while(cin>>s)
    {
        vec.push_back(s);
    }
    int size=vec.size();
    char **arr=(char **)malloc(size*sizeof(char*));
    for(size_t i=0;i!=size;++i)
    {
        arr[i]=(char *)malloc(100*sizeof(char));
    }
    for(size_t ix=0;ix!=vec.size();++ix)
    {
       strcpy(arr[ix],vec[ix].c_str());
    }
    for(size_t ix=0;ix!=vec.size();++ix)
    {
        cout<<arr[ix]<<" ";
    }
    cout<<endl;

    
    return 0;


}
