#ifndef _interp_hpp_3728273
#define _interp_hpp_3728273
#include <vector>
class Interpolation{};
class Sorted_Interpolation: public Interpolation
{
    public: 
    Sorted_Interpolation(){};
    double interpolate(double p_x, std::vector<double> p_known_x, std::vector<double> p_known_y) const;

};

#endif