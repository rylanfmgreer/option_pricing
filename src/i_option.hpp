#ifndef _I_Option_93u492y38942
#define _I_Option_93u492y38942

typedef double OptionDouble;

class I_Option
{
    public:
    virtual OptionDouble price(OptionDouble p_S) const = 0;
    virtual OptionDouble calculate_discount_factor(OptionDouble p_T) const = 0;
    virtual OptionDouble calculate_delta(OptionDouble p_T) const = 0;
};

#endif