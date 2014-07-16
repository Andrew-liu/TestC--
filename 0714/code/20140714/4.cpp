#include <iostream>
#include <string>
#include <vector>
using namespace std;

class X {
    /*
    int i;
    int j; */
    int j;
    int i;
public:
    X(int val) :
            j(val), i(j) {
    }
    void print() const
    {
        cout << "i= " << i << " j= " << j << endl;
    }
}; 

int main(int argc, const char *argv[])
{
    X x(5); //本意是i和j都为5
    x.print();
    return 0;
}
