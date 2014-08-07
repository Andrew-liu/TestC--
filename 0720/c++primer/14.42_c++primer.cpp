#include <iostream>
#include <string>
#include <vector>
using namespace std;
class CheckoutRecord
{
    public:
        CheckoutRecord(){}
        operator bool() const
        {
            return book_id;
        }
    private:
        double book_id;
        string title;
        Date date_borrowed;
        Date date_due;
        Date date_due;
        pair<string, string> borrower;
        vector< pair<string, string>* > wait_list;

};
int main(int argc, const char *argv[])
{
    
    return 0;
}
