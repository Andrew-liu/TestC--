#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Computer
{
    public:
        Computer()
            :price_(4000),
             cpu_("i5")
        {}
        void set_parameter(double price, const string &cpu)
        {
            price_ = price;
            cpu_ =cpu;
        }
        virtual double amount_price(size_t n)
        {
            return price_ * n;
        }
    protected:   
        double price_;
        string cpu_;
};
class Dell : public Computer
{
    public:
        Dell():Computer(),min_amt_(10),discount_(0.8),mark_("Dell")
        {}
        double amount_price(size_t n)
        {
            if(n > min_amt_)
            {
                cout << "Dell" << endl;
                return n * (1-discount_) * price_;
            }
            else
            {
                return n * price_;
            }
        }
    private:
        size_t min_amt_;
        double discount_;
        string mark_;
};
class Lenovo : public Computer
{
    public:
        Lenovo():Computer(),min_amt_(10),discount_(0.8),mark_("Lenovo")
        {}
        double amount_price(size_t n)
        {
            if(n > min_amt_)
            {
                cout << "Lenovo" << endl;
                return n * (1-discount_) * price_;
            }
            else
            {
                return n * price_;
            }
        }
    private:
        size_t min_amt_;
        double discount_;
        string mark_;
};
class Mac : public Computer
{
    public:
        Mac():Computer(),min_amt_(10),discount_(0.8),mark_("Mac")
        {}
        double amount_price(size_t n)
        {
            if(n > min_amt_)
            {
                cout << "Mac" << endl;
                return n * (1-discount_) * price_;
            }
            else
            {
                return n * price_;
            }
        }
    private:
        size_t min_amt_;
        double discount_;
        string mark_;
};
int main(int argc, const char *argv[])
{
    double ret1, ret2, ret3;
    Computer *com1 = new Dell();
    Computer *com2 = new Lenovo();
    Computer *com3 = new Mac();
 //   Computer t1;
   // ret = t1.amount_price(20);
    ret1 = com1->amount_price(20);
    ret2 = com2->amount_price(15);
    ret3 = com3->amount_price(12); 
    
    cout << ret1 << ret2 << ret2 << endl;
    return 0;
}
