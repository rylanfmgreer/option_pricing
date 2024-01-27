#ifndef _vanilla_bs_option_938493821
#define _vanilla_bs_option_938493821
#include "../option.hpp"

class Vanilla_BS_CallOption: public Option
{
    public:
    Vanilla_BS_CallOption(){}
    Vanilla_BS_CallOption(OptionDouble p_K, OptionDouble p_r,
            OptionDouble p_vol, OptionDouble p_ttm);
    virtual OptionDouble calculate_delta(OptionDouble p_S) const;
    virtual OptionDouble calculate_gamma(OptionDouble p_S) const;

};

class Vanilla_BS_PutOption: public Vanilla_BS_CallOption
{
    public:
    Vanilla_BS_PutOption(OptionDouble p_K, OptionDouble p_r,
            OptionDouble p_vol, OptionDouble p_ttm);
};

#endif
