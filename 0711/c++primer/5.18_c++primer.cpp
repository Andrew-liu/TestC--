#include <iostream>
#include <string>
#include <vector>
using namespace std;
void init_vector(vector<int> &vec)
{
    int x;
    while(cin>>x)
    {
        vec.push_back(x);
    }
}
bool cmp_vector(const vector<int> &vec1,const vector<int> &vec2)
{
    size_t  min=0;
    size_t i=0;
    if(vec1.size()>=vec2.size())
    {
        min=vec2.size();
    }
    else
    {
        min=vec1.size();    
    }
    for(i=0;i!=min;++i)
    {
        if(vec1[i]==vec2[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    if(i==min)
    {
        return true;
    }
}

int main(int argc, const char *argv[])
{
    vector<int> vec1,vec2;
    init_vector(vec1);
    init_vector(vec2);
    cout<<cmp_vector(vec1,vec2)<<endl;
    return 0;
}
