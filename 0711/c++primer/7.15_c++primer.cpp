#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    for(int i=1;i!=argc;++i)
    {
        cout<<argv[i]<<" ";
    }
    cout<<endl;
    return 0;
}
