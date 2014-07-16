#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main(int argc, const char *argv[])
{
    
    ostringstream oss;
    oss<<3.14;
    oss<<" ";
    oss<<1111111111111111111;
    oss<<endl;
    cout<<oss.str();
    return 0;
}
