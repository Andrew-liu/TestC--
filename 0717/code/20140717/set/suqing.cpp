#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <stdlib.h>
using namespace std;

class QingTuan
{
    public:
        QingTuan(const string &leader);
        void add(const string &business, const string &name);
        void setMercy(const string &name);
        void setHater(const string &name);
        string search(const string &business) const;
        void kill(); 
    private:
        map<string, string> list_;
        string leader_;
        set<string> mercy_;
        set<string> hater_;
};


QingTuan::QingTuan(const string &leader)
    :leader_(leader)
{}

void QingTuan::add(const string &business, const string &name)
{
    list_[business] = name;
}

string QingTuan::search(const string &business) const
{
    map<string, string>::const_iterator it =
        list_.find(business);
    if(it == list_.end())
    {
        //cout << "此人不在宿青团伙中， 无罪释放！" << endl;
        return "";
    }else{
        return it->second; 
    }

}

void QingTuan::kill() 
{
    cout << "头目 " << leader_ << " 被拖死...." << endl; 
    
    srand(1000);

    for(map<string, string>::iterator it = list_.begin(); it != list_.end(); ++it)
    {
        if(mercy_.count(it->second) == 1)
        {
            cout << "宿青宽恕了" << it->second << "当庭释放" << endl;
        }
        else if(hater_.count(it->second) == 1)
        {
            cout << "宿青不能原谅" << it->second << "判处死刑" << endl;
        }
        else
        {
            cout << "宿青在" << it->first << "公司的分身" << it->second <<  "被判处" << rand()%6 << "有期徒刑" << endl;
        }
    }

}

void QingTuan::setMercy(const string &name)
{
    mercy_.insert(name);
}

void QingTuan::setHater(const string &name)
{
    hater_.insert(name);
}

int main(int argc, const char *argv[])
{
    QingTuan Q("liubin");
    Q.add("baidu", "nanshen");
    Q.add("tencent", "liuyuan");
    Q.add("alibaba", "liuxin");
    Q.add("baihe", "xiaobaihe");
    Q.add("google", "lule");
    Q.add("apple", "lutaiyu");
    Q.add("smartisan", "linghuzhong");


    Q.setMercy("linghuzhong");

    Q.setHater("nanshen");
    Q.setHater("lule");

    cout << "在宿青同学的举报下：" << endl;
    Q.kill();
    


    return 0;
}
