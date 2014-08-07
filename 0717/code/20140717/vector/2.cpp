#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main(int argc, const char *argv[])
{
    list<int> lst;
    for (int i = 0; i < 20; i++) {
        lst.push_back(i);
    }

    for(list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
        if(*it % 2 == 0)
        {
            //lst.erase(it);
            //删除后it会失效，所以需要接收返回值
            it = lst.erase(it);
        }
    }


    for(list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}
