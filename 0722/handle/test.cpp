#include "handle.h"
#include "animal.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<Handle> vec;
    Cat c1, c2;
    Dog d1;
    Bear b1, b2, b3;
    //这里实现了一种从animal到handle的转化
    //vec.push_bakc(Handle(c1));
    vec.push_back(c1);
    vec.push_back(c2);
    vec.push_back(d1);
    vec.push_back(b1);
    vec.push_back(b2);
    vec.push_back(b3);
    for(vector<Handle>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        (*it)->display();     //animal *发生动态绑定
    }
    return 0;
}
