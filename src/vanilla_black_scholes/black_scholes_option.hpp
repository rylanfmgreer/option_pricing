#ifndef _vanilla_bs_option_938493821
#define _vanilla_bs_option_938493821
#include "../option.hpp"

class VanillaBSEuropeanCall_Option: public Option
{
    public:
    VanillaBSEuropeanCall_Option(){}
    VanillaBSEuropeanCall_Option(OptDouble p_K, OptDouble p_r,
            OptDouble p_vol, OptDouble p_ttm);
    virtual OptDouble calculate_delta(OptDouble p_S) const;
    virtual OptDouble calculate_gamma(OptDouble p_S) const;

};

class VanillaBSEuropeanCallPDE_Option: public VanillaBSEuropeanCall_Option
{
    public:
    VanillaBSEuropeanCallPDE_Option(OptDouble p_K, OptDouble p_r,
            OptDouble p_vol, OptDouble p_ttm);
};

class VanillaBSEuropeanPut_Option: public VanillaBSEuropeanCall_Option
{
    public:
    VanillaBSEuropeanPut_Option(OptDouble p_K, OptDouble p_r,
            OptDouble p_vol, OptDouble p_ttm);
};

#endif
