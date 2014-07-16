#include <iostream>
#include <string>
#include <vector>
using namespace std;
double sum(vector<double> &vec)
{
    double sum=0.0;
    for(vector<double>::iterator it=vec.begin();it!=vec.end();++it)
    {
        sum+=(*it);
    }
    return sum;
}
int main(int argc, const char *argv[])
{
    vector<double> vec;
    for(double i=0;i!=10;++i)
    {
        vec.push_back(i+1);
    }
    cout<<"double sum :"<<sum(vec)<<endl;
    return 0;
}
