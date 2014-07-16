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
    int *arr=new int[vec.size()];
    for(size_t ix=0;ix!=vec.size();ix++)
    {
        arr[ix]=vec[ix];
    }
    for(size_t i=0;i!=vec.size();++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<vec.size()<<endl;
    delete [] arr;
    return 0;
}
