#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    
    class Sales_items
    {
        public:
            double avg_price() const; //this
            bool same_isbn(const Sales_items &rhs) const
            {
                return isbn==rhs.isbn;
            }
            Sales_items():units_sold(0),revenue(0.0){}//自定义默认构造函数
            Sales_items(string &s, unsigned int i, double y)
            {
                this->isbn = s;
                this->units_sold = i;
                this->revenue = y;
            }
            void read_sales_item() const
            {
                cout << "isbn=" << isbn << "units_sold" << units_sold << "revennue" << revenue << endl;
            }
            void write_sales_item()
            {
                cin << isbn << units_sold << revenue ;
            }
            Sales_item &add_sales_item(Sales_item &rhs)
            {
                isbn+=rhs.isbn;
                units_sold+=rhs.units_sold;
                revenue+=rhs.revenus;
                return *this;
            }
        private:
            string isbn;
            unsigned int units_sold;
            double revenue;
    }
    return 0;
}

 int main(int argc, const char *argv[])
 {
     
     return 0;
 }
