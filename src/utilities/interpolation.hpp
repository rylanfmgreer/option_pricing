#ifndef _interp_hpp_3728273
#define _interp_hpp_3728273
#include <vector>
#include "../consts.hpp"
#include "gsl_interface/gsl_interface.hpp"
#include <gsl/gsl_interp.h>


class Interpolation
{
    public:
    /*
        Initialize.

        :param p_known_x: the x values of the (x, y) pairs
        :param p_known_y: the y values of the (x, y) pairs
    */
    Interpolation(const std::vector<OptDouble> p_known_x,
        const std::vector<OptDouble> p_known_y,
        const gsl_interp_type* p_interp_type=gsl_interp_linear);

    /*
        Perform standard linear interpolation.

        :param p_x: the value we want to find an interpolated y for.
        :param p_known_x: the x values we will use to interpolate
        :param p_known_y: the y values we will use to interpolate
        :return: an interpolated value y = f(p_x)

    */
    double interpolate(OptDouble p_x) const;

    private:

    // the gsl objects
    typedef std::unique_ptr<gsl_interp, decltype(&gsl_interp_free)> GSL_interp_ptr;
    GSL_interp_ptr m_interp;
    typedef std::unique_ptr<gsl_interp_accel, decltype(&gsl_interp_accel_free)> GSL_interp_accel_ptr;
    GSL_interp_accel_ptr m_interp_accel;

    // save down the (x, y) pairs
    Double_arr_ptr m_xa;
    Double_arr_ptr m_ya;

};

class LinearInterpolation : public Interpolation
{
    /*
        Class for performing Linear interpolation.
    */
    public:

    /*
        Initialize.

        :param p_known_x: the x values of the (x, y) pairs
        :param p_known_y: the y values of the (x, y) pairs
    */
    LinearInterpolation(const std::vector<OptDouble> p_known_x,
        const std::vector<OptDouble> p_known_y)
    : Interpolation(p_known_x, p_known_y, gsl_interp_linear){}
};

class CubicSplineInterpolation : public Interpolation
{
    /*
        Class for performing Cubic Spline interpolation.
    */
    public:

    /*
        Initialize.

        :param p_known_x: the x values of the (x, y) pairs
        :param p_known_y: the y values of the (x, y) pairs
    */
    CubicSplineInterpolation(const std::vector<OptDouble> p_known_x,
        const std::vector<OptDouble> p_known_y)
    : Interpolation(p_known_x, p_known_y, gsl_interp_cspline){}
};

#endif