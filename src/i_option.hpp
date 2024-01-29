#ifndef _I_Option_93u492y38942
#define _I_Option_93u492y38942
#include "consts.hpp"
#include <cmath>

class I_Option
{
    public:
    virtual OptDouble price(OptDouble p_S) = 0;
    virtual OptDouble calculate_discount_factor(OptDouble p_T) const { return exp(-m_r * p_T); }
    virtual OptDouble calculate_delta(OptDouble p_T) = 0;

    private:
    OptDouble m_r;
};

#endif