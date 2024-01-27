#ifndef _I_Option_93u492y38942
#define _I_Option_93u492y38942

typedef double OptDouble;

class I_Option
{
    public:
    virtual OptDouble price(OptDouble p_S) const = 0;
    virtual OptDouble calculate_discount_factor(OptDouble p_T) const = 0;
    virtual OptDouble calculate_delta(OptDouble p_T) const = 0;
};

#endif