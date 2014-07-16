#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, const char *argv[])
{/*
    cout<<"before"<<endl;
    throw std::runtim e_error("test");
    cout<<"after"<<endl;

    int a=4;
    int b=5;
    swap(&a,&b);
    cout<<a <<" "<<b<<endl;
    */

/*
    int  x[10];
    int  *p=x;
    cout<<sizeof(x)/sizeof(*x)<<endl;
    cout<<sizeof(p)/sizeof(*p)<<endl;
    */

    vector<string> *vec=new vector<string>(10);
    vector<string> svec(10);
    cout << svec[0]<<endl;
    return 0;
}
