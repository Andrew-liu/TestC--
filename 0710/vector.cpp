#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    //这里声明了一个int类型的空数组
    //vector不是一个完整的类型,必须加上类型信息
    //vector<int>才是合法的类型
    vector<int> vec;
    vector<string> str;
//push_back在数组后面追加元素
    vec.push_back(13);
    vec.push_back(13);
    vec.push_back(13);
    vec.push_back(13);
    vec.push_back(13);
    vec.push_back(13);
    str.push_back("string");
    str.push_back("string");
    str.push_back("string");
    str.push_back("string");
    str.push_back("string");
    
    cout<< "size:"<<vec.size()<<endl;
    for(vector<int>::size_type ix=0;ix!=vec.size();++ix)
        cout<<vec[ix]<<" ";
    cout<<endl;
    for(vector<string>::size_type i=0;i!=str.size();++i)
        cout<< str[i] <<" ";
    cout<<endl;
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
        cout<<*it<<endl;
    return 0;
}
