#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct Student
{
    string name;
    int score;
}Student;

int main(int argc, const char *argv[])
{
    int cnt=0;
    Student st;
    vector<Student> stu;
    vector<string> save;
    while(cin>>st.name>>st.score)//初始化
    {
        stu.push_back(st);
    }
    for(vector<Student>::iterator it=stu.begin();it!=stu.end();++it)
    {
        if((*it).score>=60)
        {
            save.push_back((*it).name);
            cnt++;
        }
    }
    cout<< "cnt = "<<cnt<<endl;
    for(vector<string>::iterator ix=save.begin();ix!=save.end();++ix)
    {
        cout<<*ix<<" ";
    }
    cout<<endl;
    return 0;
}
