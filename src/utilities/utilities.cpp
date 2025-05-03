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

    bool is_power_of_two(int x)
    {
        while(x > 1)
        {
            std::div_t division_result = std::div(x, 2);
            if(division_result.rem > 0)
                return false;
            x = division_result.quot;
        }
        return true;
            

    }

};