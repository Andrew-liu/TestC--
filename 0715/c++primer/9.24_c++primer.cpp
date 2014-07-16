#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<int> vec;
    vector<int> vec1;
    vec.push_back(1);
    vector<int>::iterator it = vec.begin(); 
    vector<int>::iterator ix = vec1.begin(); 
    cout << *it << endl;
    cout << *ix <<endl;
    vector<int>::reference num = vec.front(); 
    vector<int>::reference num2 = vec1.front(); 
    cout << num << endl;
    cout << num2 << endl;
    cout << vec[0] << endl;
    cout << vec1[0] << endl;
    return 0;
}
