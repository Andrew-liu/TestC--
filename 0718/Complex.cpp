#include "Complex.h"

using namespace std;

Complex::Complex():real_(0.0),imag_(0.0)
{}

Complex::Complex(double real, double imag)
    :real_(real),
     imag_(imag)
{}
Complex::~Complex()
{}

Complex &Complex::set(double a, double b)
{
    real_ = a;
    imag_ = b;
    return  *this;
}

Complex Complex::adjoin()
{
    double a = real_;
    double b = - imag_;
    Complex com(a, b);
    return com;
}

double Complex::mod()
{
    double ret = ::sqrt((real_ *real_ +imag_ * imag_));
    return ret;
}


