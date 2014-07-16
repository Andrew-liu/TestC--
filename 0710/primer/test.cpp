#include <iostream>
#include <string>
using namespace std;

void swap(int &a,int &b)
{
    int temp(a);
    a=b;
    b=temp;
}

int main(int argc, const char *argv[])
{
    string s="hello world";
    string s2="world";
    string &s1=s;
    s1="I have changed!";
    int a(10),b(5);
    cout << "before swap " << a << " " << b << endl;
    swap(a,b);
    cout << "s1=" << s1 << endl << "s=" <<s<<endl;
    cout << "after swap" << a << " " << b << endl;
    cout << (s==s2)<< endl ;
    return 0;
}
