#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
int main(int argc, const char *argv[])
{
    int i=5;
    int j=1;
    try
    {
        if(j==0)
        {
            throw exception();
        }
        else
        {
            int res=i/j;
            cout<<"res="<<res<<endl;
        }
        cout<<"calulate after"<<endl;
    }
    catch(exception &e)
    {
        cout<<"catch"<<endl;
        cout<<e.what()<<endl;
    }
    cout<<"over"<<endl;


    return 0;
}
