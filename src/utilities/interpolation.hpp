#ifndef _interp_hpp_3728273
#define _interp_hpp_3728273
#include <vector>
#include "../consts.hpp"
#include <gsl/gsl_interp.h>

class Interpolation
{
    public: 
    Interpolation(const std::vector<OptDouble> p_known_x, const std::vector<OptDouble> p_known_y);

    /*
        Perform standard linear interpolation.

        :param p_x: the value we want to find an interpolated y for.
        :param p_known_x: the x values we will use to interpolate
        :param p_known_y: the y values we will use to interpolate
        :return: an interpolated value y = f(p_x)

    */
    double interpolate(OptDouble p_x) const;

    private:
    typedef std::unique_ptr<gsl_interp, decltype(&gsl_interp_free)> GSL_interp_ptr;
    GSL_interp_ptr m_interp;
    
    typedef std::unique_ptr<gsl_interp_accel, decltype(&gsl_interp_accel_free)> GSL_interp_accel_ptr;
    GSL_interp_accel_ptr m_interp_accel;

    typedef std::unique_ptr<OptDouble[]> Double_arr_ptr;
    Double_arr_ptr m_xa;
    Double_arr_ptr m_ya;

};

#endif