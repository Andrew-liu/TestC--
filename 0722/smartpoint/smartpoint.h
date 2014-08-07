#ifndef _SMARTPOINT_
#define _SMARTPOINT_

#include <iostream>
class Animal
{
    public:
        Animal()
        {
            std::cout << "Animal..." << std::endl;
        }
        ~Animal()
        {
            std::cout << "~Animal..." << std::endl;
        }

};
class Smartpoint
{   
    public:
        Smartpoint();
        Smartpoint(Animal *ptr);
        ~Smartpoint();
        
        void reset(Animal *ptr); //更改指针指向
        const Animal *getptr() const;

        Animal &operator * () ;
        Animal *operator -> () ;
    private:
        Smartpoint(const Smartpoint &);
        Smartpoint &operator = (const Smartpoint &);
        Animal *ptr_;

};

#endif
