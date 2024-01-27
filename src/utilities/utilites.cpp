#include "utilities.hpp"

namespace Utils
{
    double normal_pdf(double p_z, boost::math::normal* p_dist)
    {
        if(p_dist == nullptr)
        {
            boost::math::normal new_normal;
            p_dist = &new_normal;
        }
        return boost::math::pdf(*p_dist, p_z);

    }
    
    double normal_cdf(double p_z, boost::math::normal* p_dist)
    {
        if(p_dist == nullptr)
        {
            boost::math::normal new_normal;
            p_dist = &new_normal;
        }
        return boost::math::cdf(*p_dist, p_z);
    }


};