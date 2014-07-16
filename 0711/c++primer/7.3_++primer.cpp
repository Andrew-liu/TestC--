#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cmp(int x,int n)
{
    int temp=x;
    for(int i=1;i!=n;++i)
    {
        x*=temp;
    }
    return x;
}
int main(int argc, const char *argv[])
{
    int x,n;
    int ans=0;
    cin>>x>>n;
    ans=cmp(x,n);
    cout<<"ans "<<ans<<endl;
    return 0;
}
