#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//函数指针
bool cmp1(int a, int b)
{
    return a>b;
}
void bubblesort(vector<int> &vec,bool (*cmp)(int,int))
{
    auto len=vec.size();
    for(size_t i=0;i<len-1;++i)
    {
        for(size_t j=0;j<len-i-1;++j)
        {
            if(!cmp(vec[j],vec[j+1]))
            {
                swap(vec[j],vec[j+1]);
            }
        }
    }

}



int main(int argc, const char *argv[])
{
    vector<int> vec;
    srand(time(NULL));
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    bubblesort(vec,cmp1);
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";    
    }
    cout<<endl;
    return 0;
}
