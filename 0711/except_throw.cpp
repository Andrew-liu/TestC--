#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
int main(int argc, const char *argv[])
{
    int i;
    try
    {
        cin>>i;
        if(i==1)
        {
            throw std::out_of_range("0");
        }
        else if(i==2)
        {
            throw std::logic_error("1");
        }
        else if(i==3)
        {
            throw std::runtime_error("2");
            }
        else
        {
            throw std::invalid_argument("3");
        }

        cout<<"continue"<<endl;
    }
        catch(std::out_of_range &e)//捕获不同的异常
        {
            cout<<"enter exception"<<endl;
            cout<<e.what()<<endl;//what用于输出设定的错误信息
        }
        catch(std::logic_error &e)
        {
            cout<<"enter exception"<<endl;
            cout<<e.what()<<endl;
        }
        catch(std::runtime_error &e)
        {
            cout<<"enter exception"<<endl;
            cout<<e.what()<<endl;
        }
        catch(std::invalid_argument  &e)
        {
            cout<<"enter exception"<<endl;
            cout<<e.what()<<endl;
        }
        catch(...)//捕获所有的异常.
        {
            cout<<"all"<<endl;
        }

        cout<<"over"<<endl;
    
    
    return 0;
}
