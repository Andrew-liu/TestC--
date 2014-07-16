#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test{
    public:
        Test(const string &name)
            :name_(name) /* 这是一条初始化语句  */
        {
            //这是一条修改语句
            //name_ = name;
        }

    private:
        const string name_;
};


int main(int argc, const char *argv[])
{
    Test t("hello");
    return 0;
}
