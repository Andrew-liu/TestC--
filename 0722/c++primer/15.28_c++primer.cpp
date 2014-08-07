#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Item_base
{
    protected:
        double price_;
};
class Bulk_item : public Item_base
{
    private:
        double discount_;
};

int main(int argc, const char *argv[])
{
    vector<Item_base> vec;
    Item_base it;
    vector<Item_base *> vec1;
    Item_base *ix = new Bulk_item;
    vec1.push_back(ix);
    vec1.push_back(ix);
    vec1.push_back(ix);
    vec1.push_back(ix);
    cout << vec.size() << endl;
    return 0;
}
