#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    
    int x = ({int y = 123;y+22;});
    cout << x << endl;
    return 0;
}
