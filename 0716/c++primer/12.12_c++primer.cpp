#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Screen
{
    public:
        typedef string::size_type index;
        Screen(const string &s, index a, index h, index w):
            content_(s),
            cursor_(a),
            height_(h),
            width_(w)
    {}       
        Screen &move(index a, index b)
        {
            height_ += a;
            width_ += b;
            return *this;
        }
        Screen &display()
        {
            cout << content_ <<endl;
            cout << height_ << endl;
            cout << width_ << endl;
            return *this;
        }
        const Screen &display() const
        {
            cout << content_ << endl;
            cout << height_ << endl;
            cout << width_ << endl;
            return *this;
        }
       
    private:
        string content_;
        index cursor_;
        index height_, width_;
        
};
int main(int argc, const char *argv[])
{
    Screen Scr("liubin", 1, 2, 3);
    Scr.move(4, 0).display();
    return 0;
}
