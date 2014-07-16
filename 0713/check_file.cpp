#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdexcept>
using namespace std;

class Query
{
    private:
        vector<string> words_;
    public:
        void open_file(ifstream &in,const string &filename)
        {
            in.close();
            in.clear();
            in.open(filename.c_str());
        }
        void read_file(ifstream &in)
        {
            string word;
            while(in>>word)
            {
                words_.push_back(word);
            }
        }
        /*
        void debug()
        {
            for(vector<string>::iterator it = words_.begin(); it != words_.end(); ++it)
            {
                cout << *it << endl;    
            }
        }
        */
        void find_word(const string &word)
        {
            for(vector<string>::iterator it = words_.begin(); it != words_.end(); ++it)
            {
                string::size_type str=it->find(word);
                if(str!=string::npos)
                {
                    cout<< *it <<" ";
                }
            }
            cout << endl;
        }
        /*
           vector<string> query_word(const string &word)
           {

           }
         */

};
int main(int argc, const char *argv[])
{
    Query Q;
    string name("The_Holy_Bible.txt");
    string word;
    ifstream in;
    Q.open_file(in,name);
    Q.read_file(in);
//    Q.debug();
    while(cin>>word)
    {
        Q.find_word(word);
    }
    return 0;
}


/*
   void open_file(ifstream &in,string filename)
   {
   in.close();
   in.clear();
   in.open(filename.c_str());
   }

   int main(int argc, const char *argv[])
   {
   string filename("The_Holy_Bible.txt") ;
   string word;
   string file;
   ifstream in;

   while(cin>>word)
   {
   open_file(in,filename);
   while(in>>file)
   {
   if(strstr(file.c_str(),word.c_str())!=NULL)
   {
   cout << file << " ";         
   }
   else
   {
   continue;
   }
   }
   cout << endl;
//        cout << cin.good() << cin.fail() <<endl;
cin.clear();
in.close();
}
in.close();
return 0;
}*/
