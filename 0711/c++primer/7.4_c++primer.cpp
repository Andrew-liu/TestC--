#include <iostream>
#include <string>
#include <vector>
using namespace std;

int myabs(int a)
{
    return -a;
}
int main(int argc, const char *argv[])
{
    int x;
    cin>>x;
    x=myabs(x);
    cout<<" abs "<<x<<endl;
    return 0;
}
