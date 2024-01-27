#ifndef _black_scholes_i_option_93840928
#define _black_scholes_i_option_93840928
#include "../../i_option.hpp"
#include <boost/math/distributions/normal.hpp>

class Vanilla_BS_I_CallOption: public I_Option
{
    public:
    Vanilla_BS_I_CallOption(OptionDouble p_K, OptionDouble p_r,
            OptionDouble p_vol, OptionDouble p_ttm);
    virtual OptionDouble price(OptionDouble p_S) const;
    friend class Vanilla_BS_I_PutOption;
    virtual OptionDouble calculate_discount_factor(OptionDouble p_T) const;
    
    OptionDouble get_strike() const {return m_K; }
    OptionDouble get_rate() const {return m_r; }
    OptionDouble get_vol() const { return m_vol; }
    OptionDouble get_ttm() const { return m_ttm; }
    
    protected:
    OptionDouble m_K;
    OptionDouble m_r;
    OptionDouble m_vol;
    OptionDouble m_ttm;
    OptionDouble m_var;
    OptionDouble m_sqrt_ttm;
    OptionDouble price_call(OptionDouble p_S) const;
    OptionDouble calc_d1(OptionDouble p_S) const;
    OptionDouble calc_d2(OptionDouble p_d1) const;
};

class Vanilla_BS_I_PutOption: public Vanilla_BS_I_CallOption
{
    using Vanilla_BS_I_CallOption::Vanilla_BS_I_CallOption;
    virtual OptionDouble price(OptionDouble p_S) const;
};


#endif