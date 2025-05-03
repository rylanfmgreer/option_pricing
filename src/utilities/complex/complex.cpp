#include "complex.hpp"
Complex Complex::invert() const
{
   double det = 1.0 / (real * real - imag * imag);
   double new_real = det * real;
   double new_imag = det * -imag;
   return Complex(new_real, new_imag);
}

std::vector<Complex> create_complex_vector_from_real_vector(const std::vector<OptDouble>& p_real_vector)
{
    std::vector<Complex> complex_vector(p_real_vector.size());
    std::transform(p_real_vector.begin(), p_real_vector.end(), complex_vector.begin(), [](OptDouble x){ return Complex(x, 0); });
    return complex_vector;
}
