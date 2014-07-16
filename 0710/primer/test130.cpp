#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, const char *argv[])
{
    /*     
     short short_value=32767;
     short i=1;
     short_value+=i;
     cout<< short_value <<endl;
     */

    cout<< (12/3*4+5*15+24%4/2)<<endl;
    cout<<(-30 *3 +21/5)<<endl;
    cout<<(-30 +3*21/5)<<endl;
    cout<<(30/3*21%5)<<endl;
    /*
    int num;
    cin>>num;
    if(num%2==0)
    {
        cout<<"not odds"<<endl;
       }
    else
    {
        cout<<"odd"<<endl;
    }
    */
    int i;
    double d;
    d=i=3.5;
    cout <<d <<" "<<i<<endl;
    i=d=3.5;
    cout<<i<<" "<<d<<endl;
    i=3;
    i+=i+1;
    cout<<i<<endl;
     return 0;
 }
