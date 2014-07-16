class Test
{
    public:
        setValue(const string &s, int a);
    private:
        int a_ ;
        string s_;
};


int main(int argc, const char *argv[])
{
    void (Test::*func)(const string &, int) = &Test::setValue;
    Test t;
    //采用对象使用函数指针
    (t.*func)("hello",12);
    
    Test *pt = &t;
    (pt->*func)("test",99);

    return 0;
}
