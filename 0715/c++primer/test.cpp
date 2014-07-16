#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    
    vector<int> vec;
    vector<string> no;

    //vec.reserve(50);

    vec.push_back(1);
    cout << "size" << vec.size() << endl;
    //cout << "vec " << vec.capacity() << endl;
    cout << "vec " << vec.capacity() << endl;
    //cout << "vec " << vec.capacity() << endl;
   // cout << "no " << no.capacity() << endl;

    for(vector<int>::size_type ix = 0; ix != 24; ++ix )
    {
            vec.push_back(ix);
    }
    cout << "vec " << vec.capacity() << endl;
    //cout << "vec " << vec.capacity() << endl;
    cout << "no " << no.capacity() << endl;

    return 0;
}
