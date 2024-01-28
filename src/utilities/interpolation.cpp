#include <algorithm>
#include <cmath>
#include "interpolation.hpp"

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