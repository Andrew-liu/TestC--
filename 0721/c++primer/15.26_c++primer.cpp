#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Disc_item
{
    public:
        Disc_item(): price_(1000), discount_(0.8)
        {}
        ~Disc_item();
        double discount() = 0;
    protected:
        double price_;
        double discount_;
};
class New_item :public Disc_item
{
    public:
        double discount()
        {
            return price_ * discount_;
        }
};
int main(int argc, const char *argv[])
{
    Disc_item d1;
    return 0;
}
