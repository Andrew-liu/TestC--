#ifndef PTR_VECTOR_H
#define PTR_VECTOR_H 

#include "NonCopyable.h"
#include <vector>


//继承vector 生成一个泛型vector
template <typename T>
class PtrVector : public std::vector<T*>,
                  private NonCopyable
{
    public:
        ~PtrVector()
        {
            clear();
        }
        //由于pushback进行的是值拷贝
        //通过T* 才可以进行有内存空间拷贝
        //这样才是真正意义上的拷贝
        void push_back(T *val)
        {
            std::vector<T*>::push_back(val);
        }
        void clear()
        {
            typename std::vector<T*>::iterator it;
            for(it = std::vector<T*>::begin(); it != std::vector<T*>::end(); ++it)
            {
                delete *it;  // *it指的是 T*
            }
            //调用基类的clear，真正释放元素
            std::vector<T*>::clear(); 
        }
};




#endif  /*PTR_VECTOR_H*/
