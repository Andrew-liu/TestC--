#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Account
{
    public:
        Account();
        void increase();
        static double rate();
        static void setrate(double);
        void show();
    private:
        string owner_;
        double money_;
        static double rate_;
 //       static double initrate();

};
Account::Account():owner_("liubin"),money_(10000)
{}
double Account::rate_ = 0.21;
void Account::increase()
{
    money_ = money_ + money_ * rate_;
}
double Account::rate()
{
    return rate_;
}
void Account::setrate(double newrate)
{
    rate_ = newrate;
}
void Account::show()
{
    cout << owner_ << " " << money_ << " " << rate_ << endl;
}
int main(int argc, const char *argv[])
{
    Account ac;
    ac.increase();
    ac.show();
    ac.setrate(0.30);
    ac.increase();
    ac.show();
   
    return 0;
}
