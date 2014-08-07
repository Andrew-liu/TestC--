#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
bool find_mid(const vector<T> &vec)
{
    vector<T> vec1(vec);
    typename vector<T>::size_type mid = vec1.size() / 2;
    if(vec.size() % 2 == 0)
    {
        return false;
    }
    sort(vec1.begin(),vec1.end());
    if(vec1[mid] > vec1[mid - 1] && vec[mid] < vec1[mid + 1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, const char *argv[])
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << find_mid(vec) << endl;
    return 0;
}
