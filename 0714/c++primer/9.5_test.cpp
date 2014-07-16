#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
class Foo
{
    private:
        int x;
    public:
        Foo(int i):x(i)
        {
        }
        ~Foo()
        {}
   
        void print()
        {
            cout << x << endl;
        }
};

int main(int argc, const char *argv[])
{
    //vector<cin> myfuck;
    list<Foo> mylist(10,1);
    for(list<Foo>::iterator it = mylist.begin(); it != mylist.end(); ++it){
         it->print();
    }
        
    return 0;
}
