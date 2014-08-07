#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
void print(T &vec)
{
    for(typename T::size_type it = 0; it != vec.size(); ++it)
    {
        cout << vec[it] <<" " << flush;
    }
    cout << endl;
}
template <typename T>
void newprint(T beg, T end)
{
    while(beg != end)
    {
        cout << (*beg) << " " << flush;
        ++beg;
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    vector<int> vec;
    vec.push_back(11);
    vec.push_back(11);
    vec.push_back(11);
    vec.push_back(11);
    vec.push_back(11);
    vec.push_back(11);
    print(vec);
    newprint(vec.begin(), vec.end());
    return 0;
}
