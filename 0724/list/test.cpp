#include <iostream>
#include <string>
#include <vector>
#include "List.h"

using namespace std;

int main(int argc, const char *argv[])
{
    int ret;
    List<int> L;
    L.TailCreate();
    L.Print();
    cout << "the list length "<< L.GetLength() << endl;
    L.Insert(3,8);
    L.Print();
    L.Delete(4,ret);
    cout << "the element was deleted is " << ret <<endl;
    L.Print();
    
    return 0;
}
