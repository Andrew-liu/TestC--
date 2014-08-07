#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_ 

//继承Noncopyable的类对象，均失去了值语义
//用于禁用复制构造函数和赋值操作符
class NonCopyable
{
    public:
        NonCopyable() {}
        ~NonCopyable() {}
    private:
        NonCopyable(const NonCopyable &);
        void operator=(const NonCopyable &);
};

#endif  /*NONCOPYABLE_H_*/
