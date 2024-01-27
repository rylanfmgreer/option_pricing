#ifndef _black_scholes_i_option_93840928
#define _black_scholes_i_option_93840928
#include "../../i_option.hpp"
#include <boost/math/distributions/normal.hpp>

class Vanilla_BS_I_CallOption: public I_Option
{
    friend class Vanilla_BS_I_PutOption;
    friend class Vanilla_BS_CallOption;

    protected:
    Vanilla_BS_I_CallOption(OptionDouble p_K, OptionDouble p_r,
            OptionDouble p_vol, OptionDouble p_ttm);
    virtual OptionDouble price(OptionDouble p_S) const;
    OptionDouble price_call(OptionDouble p_S) const;

    const OptionDouble m_K;
    const OptionDouble m_r;
    const OptionDouble m_vol;
    const OptionDouble m_ttm;
    OptionDouble m_var;
    OptionDouble m_sqrt_ttm;
    OptionDouble m_kert;

    private:
    virtual OptionDouble calculate_discount_factor(OptionDouble p_T) const;
    OptionDouble calc_d1(OptionDouble p_S) const;
    OptionDouble calc_d2(OptionDouble p_d1) const;
    void precalculate();
    Vanilla_BS_I_CallOption();
};

class Vanilla_BS_I_PutOption: public Vanilla_BS_I_CallOption
{
    protected:
    using Vanilla_BS_I_CallOption::Vanilla_BS_I_CallOption;
    friend class Vanilla_BS_PutOption;
    virtual OptionDouble price(OptionDouble p_S) const;
};


#endif