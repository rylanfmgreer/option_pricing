#ifndef _option_utils_903248902384902
#define _option_utils_903248902384902
#include <boost/math/distributions/normal.hpp>
#include <vector>
#include "../consts.hpp"

namespace Utils
{   


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

    bool is_power_of_two(int x);




};

#endif