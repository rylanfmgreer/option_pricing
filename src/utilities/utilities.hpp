#ifndef _option_utils_903248902384902
#define _option_utils_903248902384902
#include <boost/math/distributions/normal.hpp>
#include <vector>

namespace Utils
{
    double normal_pdf(double p_z, boost::math::normal* p_dist=nullptr);
    double normal_cdf(double p_z, boost::math::normal* p_dist=nullptr);

    template<typename T>
    T* vector_to_array(const std::vector<T> p_v)
    {
        T* arr = new T[p_v.size()];
        for(int i(0); i < p_v.size(); ++i)
            arr[i] = p_v[i];
        return arr;
    }

};

#endif