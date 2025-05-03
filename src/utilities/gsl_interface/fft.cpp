#include "gsl_interface.hpp"
#include <gsl/gsl_fft_complex.h>
#include <cassert>
#include "../utilities.hpp"

double* Utils::unpack_complex_vector_into_complex_array(const std::vector<Complex>& p_v)
{    
    double* complex_arr = new double[p_v.size() * 2];
    for(int i(0); i < p_v.size(); ++i)
    {
        complex_arr[2 * i] = p_v[i].real;
        complex_arr[2 * i + 1] = p_v[i].imag;
    }
    return complex_arr;
}
std::vector<Complex> Utils::fft(const std::vector<Complex>& p_v)
{
    double* complex_arr = unpack_complex_vector_into_complex_array(p_v);
    gsl_fft_complex_radix2_forward(complex_arr, 1, p_v.size());
}
