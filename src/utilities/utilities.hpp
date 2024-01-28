#ifndef _option_utils_903248902384902
#define _option_utils_903248902384902
#include <boost/math/distributions/normal.hpp>
#include <vector>
#include "../consts.hpp"
#include <gsl/gsl_vector.h>

namespace Utils
{
    typedef std::shared_ptr<gsl_vector, decltype(&gsl_vector_free)> gsl_sp;

    /*
        Wrapper function to calculate normal pdf and cdf/

        :param p_z: the value to calculate the pdf or cdf for
        :param p_dist: a pointer to an existing distribution (optional)
        :return: N'(p_z) or N(p_z)
    */
    OptDouble normal_pdf(OptDouble p_z, boost::math::normal* p_dist=nullptr);
    OptDouble normal_cdf(OptDouble p_z, boost::math::normal* p_dist=nullptr);

    /*
        Function to write a vector to an array.

        :param p_v: vector to write to dynamically allocated array
        :return: ptr to dynamically allcoted array
    */
    template<typename T>
    T* vector_to_array(const std::vector<T> p_v)
    {
        T* arr = new T[p_v.size()];
        for(int i(0); i < p_v.size(); ++i)
            arr[i] = p_v[i];
        return arr;
    }

    std::vector<OptDouble> solve_tridiagonal_system(
        const std::vector<OptDouble> p_subdiagonal,
        const std::vector<OptDouble> p_diagonal,
        const std::vector<OptDouble> p_superdiagonal, 
        const std::vector<OptDouble> p_b);
    
    gsl_sp create_gsl_vector_from_std_vector( const std::vector<OptDouble> p_v);
    std::vector<OptDouble> create_std_vector_from_gsl_vector(const gsl_sp p_p);


};

#endif