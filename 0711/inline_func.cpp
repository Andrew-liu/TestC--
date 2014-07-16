#include <iostream>
#include <string>
#include <vector>
using namespace std;
//
//
//这是一个宏函数,在预编译期间被替换成了相应的代码 
//
#define SWAP(a,b)\
{ int temp=*a;\
    *a=*b;\
    *b=temp;\
    }
/*
 *
 *整个一个内联函数,在代码编译期间进行扩展
 */
inline void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//不进行调用不检查宏函数的语法错误
#define fun{\
gahlghaag\
}
//不进行调用检查内联函数的语法错误
inline void func()
{
    ahglahlghalhga
}
int main(int argc, const char *argv[])
{
    int a=3,b=2;
    cout<<a<<" "<<b<<endl;
//    SWAP(&a,&b);//发生替换,不是值传递!
    swap(&a,&b);
    cout<<a<<" "<<b<<endl;

    return 0;
}
