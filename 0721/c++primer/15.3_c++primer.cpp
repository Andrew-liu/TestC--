#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Item_base
{
    public:
        Item_base(const string book = " ", double sales_price = 0.0)
            :isbn(book),
            price(sales_price)
        {}
        string book() const 
        {
            return isbn;
        }
        virtual double net_price(size_t n) const
        {
            return n*price;
        }
        virtual ~Item_base()
        {}
    private:
        string isbn;
    protected:
        double price;

};
class Bulk_item: public Item_base{
    public:
        double net_price(size_t n) const
        {
            if(n > min_qty)
            {
                return n*(1-discount)*price;
            }
            else
            {
                return n*price;
            }
        }
        double limit_price(size_t n) const
        {
            if(n > min_qty && n < lim_qty)
            {
                return  lim_qty * (1 - discount) * price;
            }
            else
            {
                return (n - lim_qty) * price;
            }
        }
    private:
        size_t min_qty;
        size_t lim_qty;
        double discount;
};
