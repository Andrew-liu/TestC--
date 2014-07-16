#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> vec; //初始化为空串
    vector<string> vec2(vec);
    string sa[6] = {"hel","world","how","are","you","ye"};
    vector<string> vec3(sa,sa+6);//string 数组放入vector
    vector<string> vec4(10,"hello");
    for(vector<string>::iterator it = vec3.begin(); it != vec3.end(); ++it)
    {
        cout << *it << endl;    
    }
    for(vector<string>::iterator it = vec4.begin(); it != vec4.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
