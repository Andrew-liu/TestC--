#include <iostream>
#include <string>
#include <vector>
using namespace std;
class CheckoutRecord
{
        friend ostream &operator << (ostream &out, const CheckoutRecord &other);
        friend istream &operator >> (istream &in, const CheckoutRecord &other);
    public:
        CheckoutRecord &operator = (const CheckoutRecord &other);
        pair<string, string> &operator [] (vector< pair<string, string> *>::size_type index)
        {
            return *(wait_list[index]);
        }
    private:
        double book_id;
        string title;
        Date date_borrowed;
        Date date_due;
        pair<string, string> borrower;
        vector< pair<string, string>* > wait_list;
        

}
CheckoutRecord &CheckoutRecord::operator = (const CheckoutRecord &other)
{
    book_id = other.book_id;
    title = other.title;
    date_borrowed = other.date_borrowed;//调Date的重载 =
    date_due = other.date_due;
    borrower = other.borrower;
    wait_list(other.wait_list);
    return *this;
}


ostream &operator << (ostream &out, const CheckoutRecord &other)
{
    out << other.book_id << other.title << other.date_borrowed << endl << other.date_due << borrower.first << borrower.second <<endl;
    for(vector< pair<string, string> * >::const_iterator it = wait_list.begin(); it != wait_list.end(); ++it)
    {
       out << (*it)->first << (*it)->second ;
    }
    return out;
}
istream &operator >> (istream &in, CheckoutRecord &other)
{
    in >> other.book_id >> other.title >> other.date_borrowed >> other.date_due >> borrower.first >>borrower.second ;
    if(!in)
    {
        other = CheckoutRecord();
        return in;
    }
    other.wait_list.clear();
    while(in) //知道输入不正常才结束
    {
        pair<string, string>* pt = new pair<string, string>;
        in >> pt->first >> pt->second;
        if(!in)
        {
            other = CheckoutRecord;
            return in;
        }
        wait.list.push_back(pt);
    }
    return in;
}
