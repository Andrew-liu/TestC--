#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sales_item
{
    public:
        Sales_item &operator + (const Sales_item &other);
        Sales_item &operator +=(const Sales_item &other);
    private:
        friend std::istream &operator >> (std::istream &in, 
                                          Sales_item &other);
        friend std::ostream &operator << (std::ostream &out,
                                          const Sales_item &other);

};
