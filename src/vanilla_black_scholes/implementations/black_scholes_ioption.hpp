#ifndef _black_scholes_i_option_93840928
#define _black_scholes_i_option_93840928
#include "../../i_option.hpp"
#include <boost/math/distributions/normal.hpp>

class VanillaBSEuropeanCall_I_Option: public I_Option
{
    friend class VanillaBSEuropeanPut_I_Option;
    friend class VanillaBSEuropeanCall_Option;

    protected:
    VanillaBSEuropeanCall_I_Option(OptDouble p_K, OptDouble p_r,
            OptDouble p_vol, OptDouble p_ttm);
    virtual OptDouble price(OptDouble p_S);
    virtual OptDouble calculate_delta(OptDouble p_S) const;
    virtual OptDouble calculate_gamma(OptDouble p_S) const;


    OptDouble price_call(OptDouble p_S) const;
    OptDouble call_delta(OptDouble p_S) const;

    const OptDouble m_K;
    const OptDouble m_r;
    const OptDouble m_vol;
    const OptDouble m_ttm;
    OptDouble m_var;
    OptDouble m_sqrt_ttm;
    OptDouble m_kert;

    private:
    virtual OptDouble calculate_discount_factor(OptDouble p_T) const;
    OptDouble calc_d1(OptDouble p_S) const;
    OptDouble calc_d2(OptDouble p_d1) const;
    void precalculate();
    VanillaBSEuropeanCall_I_Option();
};

class VanillaBSEuropeanPut_I_Option: public VanillaBSEuropeanCall_I_Option
{
    protected:
    using VanillaBSEuropeanCall_I_Option::VanillaBSEuropeanCall_I_Option;
    friend class VanillaBSEuropeanPut_Option;
    virtual OptDouble price(OptDouble p_S);
    virtual OptDouble calculate_delta(OptDouble p_S) const;

};


#endif