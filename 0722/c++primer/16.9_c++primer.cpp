#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename U, typename T>
U myfind(U beg, U end,const T &s)
{
    while(beg != end)
    {
        if(*beg == s)
        {
            return beg;
        }
        else
        {
            ++beg;
        }
    }
    return end;
}
int main(int argc, const char *argv[])
{
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vector<int>::iterator ix = myfind(vec1.begin(), vec1.end(), 2);
    cout << *ix << endl;

    return 0;
}
