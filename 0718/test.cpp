#include "Complex.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Complex a(1,2);
    cout << a << endl;
    Complex b(3,4);
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a.adjoin() << endl;
    cout << a.mod() <<endl;
    Complex c;
    cin >> c;
    cout << c << endl;
    return 0;
}
