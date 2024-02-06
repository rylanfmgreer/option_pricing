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

    /*
        Turn an array of size p_n_elements into a std::vector.

        :param p_arr: pointer to array
        :param p_n_elements: size of p_arr
        :return: vector with same elements
    */
    template<typename T>
    std::vector<T> array_to_vector(const T* p_arr, size_t p_n_elements)
    {
        std::vector<T> new_vector;
        new_vector.reserve(p_n_elements);
        for(size_t idx; idx<p_n_elements; ++idx)
            new_vector.push_back( p_arr[idx] );
        return new_vector;
    }

    bool is_power_of_two(int x);

};

#endif