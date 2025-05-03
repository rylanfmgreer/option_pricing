#ifndef complex_hpp_options
#define complex_hpp_options
#include <vector>
#include "../../consts.hpp"

class Complex
{
    public:
    Complex(double r=0.0, double i=0.0) : real(r), imag(i){}
    double real;
    double imag;

    inline Complex conjugate() const{ return Complex(real, -imag); }
    Complex invert() const;

    inline Complex add(const Complex& z) const { return Complex(real + z.real, imag + z.imag); }
    inline Complex subtract(const Complex& z) const { return Complex(real - z.real, imag - z.imag); }
    inline Complex multiply(const Complex& z) const { return Complex(real  * z.real - imag * z.imag, imag * z.real + real * z.imag);}
    inline Complex divide(const Complex& z) const { return multiply( z.invert()); }

};

std::vector<Complex> create_complex_vector_from_real_vector(const std::vector<OptDouble>& p_real_vector);
#endif