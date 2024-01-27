#include "interpolation.hpp"
#include <algorithm>
#include <cmath>

double Sorted_Interpolation::interpolate(double p_x,
    std::vector<double> p_known_x, std::vector<double> p_known_y) const
{
    auto lb = std::lower_bound(p_known_x.begin(), p_known_x.end(), p_x);
    int index_higher = std::distance(p_known_x.begin(), lb);
    double y_after = p_known_y[index_higher];
    double y_before = p_known_y[index_higher-1];
    double w_after = (p_x - *(lb - 1)) / (*lb - *(lb - 1));
    double w_before = 1. - w_after;
    double z = w_before * y_before + w_after * y_after;
    return z;
}