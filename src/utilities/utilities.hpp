#ifndef _option_utils_903248902384902
#define _option_utils_903248902384902
#include <boost/math/distributions/normal.hpp>

namespace Utils
{
    double normal_cdf(double p_z, boost::math::normal* p_dist=nullptr);    

};

#endif