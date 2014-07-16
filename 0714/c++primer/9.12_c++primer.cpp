#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool search(vector<int>::iterator beg,
            vector<int>::iterator end,
            int num)
{
    while(beg != end)
    {
        if(*beg == num)
        {
            break;
        }
        else
        {
            ++beg;
        }
    }
    if(beg==end)
    {
        return false;
    }
    else
        return true;
}
int main(int argc, const char *argv[])
{
    bool flag;
    int num;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cin >> num;
    flag = search(vec.begin(),vec.end(),num);
    cout << "flag = " << flag << endl ;

    return 0;
}
