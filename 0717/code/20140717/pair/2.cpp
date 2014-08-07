#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, const char *argv[])
{
    vector<pair<string, double> > vec;

    vec.push_back(make_pair("beijing", 31));
    vec.push_back(make_pair("tianjin", 34));
    vec.push_back(make_pair("shijiazhuang", 35));
    vec.push_back(make_pair("taiyuan", 33));

    string city = "tianjin";
    for(vector<pair<string, double> >::iterator it = vec.begin(); it != vec.end(); ++it){
        // *it   pair
        // (*it).first   pair.frist
        if(it->first == city){
            cout << city << " : " << it->second << endl;
            break;
        }
    }
    

    return 0;
}
