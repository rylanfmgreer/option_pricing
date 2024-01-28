#include <algorithm>
#include <cmath>
#include "interpolation.hpp"
#include "utilities.hpp"
double Sorted_Interpolation::interpolate(OptDouble p_x,
    std::vector<OptDouble> p_known_x,
    std::vector<OptDouble> p_known_y) const
{
    // find the index above in x-space
    auto lb = std::lower_bound(p_known_x.begin(), p_known_x.end(), p_x);
    unsigned int index_higher = std::distance(p_known_x.begin(), lb);
    
    // fid the y above and the y below
    OptDouble y_above = p_known_y[index_higher];
    OptDouble y_below = p_known_y[index_higher-1];

    // calculate the weights applied to each
    OptDouble w_above = (p_x - *(lb - 1)) / (*lb - *(lb - 1));
    OptDouble w_before = 1. - w_above;

    // return the weighted sum
    return w_before * y_below + w_above * y_above;
}

double Sorted_Interpolation::gsl_interpolate(OptDouble p_x, std::vector<OptDouble> p_known_x, std::vector<OptDouble> p_known_y) const
{
    GSL_interp_ptr my_interp_ptr(gsl_interp_alloc(gsl_interp_linear, p_known_x.size()), &gsl_interp_free);
    GSL_interp_accel_ptr my_accel_ptr(gsl_interp_accel_alloc(), &gsl_interp_accel_free);
    Double_arr_ptr known_x( Utils::vector_to_array(p_known_x) );
    Double_arr_ptr known_y( Utils::vector_to_array(p_known_y) );
    gsl_interp_init(my_interp_ptr.get(), known_x.get(), known_y.get(), p_known_x.size());
    return  gsl_interp_eval(my_interp_ptr.get(), known_x.get(), known_y.get(), p_x, my_accel_ptr.get());
}