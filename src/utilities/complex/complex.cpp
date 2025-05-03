#include "complex.hpp"
#include <cmath>

Complex Complex::invert() const
{
    /*
        z * w = 1
        (a + bi) * (c + di) = 1 + 0i
        ac + bci + adi - bd = 1 + 0i
        ac - bd = 1
        bc + ad = 0

        a -b  c  = 1
        b  a  d  = 0
    */
   double inv_det = 1.0 / det();
   double new_real = inv_det * real;
   double new_imag = inv_det * -imag;
   return Complex(new_real, new_imag);
}

double Complex::det() const
{
    return real * real + imag * imag;
}
double Complex::norm() const
{
    return sqrt(det());
}

std::vector<Complex> create_complex_vector_from_real_vector(const std::vector<OptDouble>& p_real_vector)
{
    std::vector<Complex> complex_vector(p_real_vector.size());
    std::transform(p_real_vector.begin(), p_real_vector.end(), complex_vector.begin(), [](OptDouble x){ return Complex(x, 0); });
    return complex_vector;
}