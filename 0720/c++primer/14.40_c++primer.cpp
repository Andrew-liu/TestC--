#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sales_item
{
    public:
        Sales_item():revenue(0),price(0)
    {}
        operator string() const
        {
            return isbn;
        }
        operator double() const 
        {
            return revenue;
        }
    private:
        string isbn;
        double revenue;
        int price;
};

int main(int argc, const char *argv[])
{
    
    return 0;
}
