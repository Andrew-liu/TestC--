#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Screen
{
    public:
        typedef string::size_type index;
        Screen(const string &content,const index &cursor,const index &hei,const index &wid);
    private:
        string content_;
        index cursor_;
        index height_,width_;

};
Screen::Screen(const string &content,const index &cursor, const index &hei,const index &wid): content_(content),
                cursor_(cursor),
                height_(hei),
                width_(wid)
{}
int main(int argc, const char *argv[])
{
    
    return 0;
}
