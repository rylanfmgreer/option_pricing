#include "gsl_interface.hpp"
#include <gsl/gsl_fft_complex.h>
#include <cassert>
#include <algorithm>
#include <cmath>
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

std::vector<Complex> Utils::pack_double_arr_into_complex_array(double* complex_array, int n_complexes)
{
    std::vector<Complex> output_arr(n_complexes);
    for(int i(0); i < n_complexes; ++i)
    {
        output_arr[i].real = complex_arr[2 * i];
        output_arr[i].imag = complex_arr[2 * i + 1];
    }
    return output_arr;
}


std::vector<Complex> Utils::fft(const std::vector<Complex>& p_v)
{
    double* complex_arr = unpack_complex_vector_into_complex_array(p_v);
    gsl_fft_complex_radix2_forward(complex_arr, 1, p_v.size());
    std::vector<Complex> resulting_arr = pack_double_arr_into_complex_array(complex_arr);
    double sqrt_n = sqrt(p_v.size());
    std::transform(resulting_arr.begin(), resulting_arr.end() [sqrt_n](Complex x) { return x / sqrt_n; })
    return resulting_arr;
}
