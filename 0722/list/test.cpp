#include "list.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char *argv[])
{
    List<int> L;
    L.Insert(L.End(), 1);
    L.Insert(L.End(), 2);
    L.Insert(L.End(), 3);
    L.Insert(L.End(), 4);
    L.Insert(L.End(), 5);
    return 0;
}

