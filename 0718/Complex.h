#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
class Complex
{
    friend std::istream &operator >> (std::istream &, Complex &);
    friend std::ostream &operator << (std::ostream &, const Complex &);
    friend Complex operator + (const Complex &, const Complex &);
    friend Complex operator - (const Complex &, const Complex &);
    friend Complex operator * (const Complex &, const Complex &);
    friend Complex operator / (const Complex &, const Complex &);
    public:
        Complex();
        Complex(double real, double imag);
        ~Complex();
        Complex &set(double a, double b);
        Complex adjoin();
        double mod();
    private:
        double real_;
        double imag_;
        
};
inline std::istream &operator >> (std::istream &in, Complex &other)
{
    double a, b;
    in >> a >> b;
    if(in)
    {
        other.set(a, b);
    }
    else
    {
        other.set(0.0, 0.0);
    }
    return in;
    
}
inline std::ostream &operator << (std::ostream &out, const Complex &other)
{
    out << other.real_ << "+" << "(" << other.imag_ << "i" << ")";
    return out;
}
inline Complex operator + (const Complex &num1, const Complex &num2)
{
    double a = num1.real_ + num2.real_;
    double b = num1.imag_ + num2.imag_;
    Complex ret(a, b);
    return ret;
}
inline Complex operator - (const Complex &num1, const Complex &num2)
{
    double a = num1.real_ - num2.real_;
    double b = num1.imag_ - num2.imag_;
    Complex ret(a, b);
    return ret;
}
inline Complex operator * (const Complex &num1, const Complex &num2)
{
    double a = (num1.real_ * num2.real_) - (num1.imag_ * num2.imag_);
    double b = (num1.imag_ * num2.real_) + (num1.real_ * num2.imag_);
    Complex ret(a, b);
    return ret;
}
//调用共轭复数和复数乘法
inline Complex operator / (const Complex &num1, const Complex &num2)
{
    double a = (num1.real_*num2.real_+num1.imag_*num2.imag_)/(num2.real_*num2.real_ + num2.imag_* num2.imag_);
    double b = (num1.imag_*num2.real_ - num1.real_*num2.imag_)/(num2.real_*num2.real_ + num2.imag_*num2.imag_);
    Complex ret(a, b);
    return ret;
}

#endif
