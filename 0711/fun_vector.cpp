#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
void swap_point(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
template <typename M>
void swap1(M &a,M &b)
{
    M temp=a;
    a=b;
    b=temp;
}

int main(int argc, const char *argv[])
{
        
    int i=1,j=2;
    int *a=&i;
    int *b=&j;
    cout<< a<<" "<<b<<endl;
   // swap_point(&a,&b);
    swap1(a,b);
    cout << a <<" "<<b<<endl;
    return 0;
}
