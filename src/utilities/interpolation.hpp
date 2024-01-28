#ifndef _interp_hpp_3728273
#define _interp_hpp_3728273
#include <vector>
#include "../consts.hpp"


class Interpolation{};
class Sorted_Interpolation: public Interpolation
{
    public: 
    Sorted_Interpolation(){};

    /*
        Perform standard linear interpolation.

        :param p_x: the value we want to find an interpolated y for.
        :param p_known_x: the x values we will use to interpolate
        :param p_known_y: the y values we will use to interpolate
        :return: an interpolated value y = f(p_x)

    */
    double interpolate(OptDouble p_x, std::vector<OptDouble> p_known_x, std::vector<OptDouble> p_known_y) const;

};

#endif