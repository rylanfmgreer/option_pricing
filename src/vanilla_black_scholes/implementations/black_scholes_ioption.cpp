#include <cmath>
#include "black_scholes_ioption.hpp"
#include "../../utilities/utilities.hpp"

Vanilla_BS_I_CallOption::Vanilla_BS_I_CallOption(
    OptionDouble p_K, OptionDouble p_r,
    OptionDouble p_vol, OptionDouble p_ttm)
    :m_K(p_K), m_r(p_r), m_vol(p_vol), m_ttm(p_ttm)
{
        precalculate();
}


OptionDouble Vanilla_BS_I_CallOption::price(OptionDouble p_S) const
{
    return price_call(p_S);
}


OptionDouble Vanilla_BS_I_CallOption::price_call(OptionDouble p_S) const
{
    OptionDouble d1 = calc_d1(p_S);
    OptionDouble d2 = calc_d2(d1);
    boost::math::normal new_normal;
    return (p_S * Utils::normal_cdf(d1, &new_normal)
        - m_kert * Utils::normal_cdf(d2, &new_normal) );
}


OptionDouble Vanilla_BS_I_CallOption::calc_d1(OptionDouble p_S) const
{
    OptionDouble lnsk = log(p_S / m_K);
    OptionDouble rsigt = (m_r +  0.5 * m_var) * m_ttm;
    return (lnsk + rsigt) / (m_vol * m_sqrt_ttm);

}


OptionDouble Vanilla_BS_I_CallOption::calc_d2(OptionDouble p_d1) const
{
    return p_d1 - m_vol * m_sqrt_ttm;
}


OptionDouble Vanilla_BS_I_CallOption::calculate_discount_factor(OptionDouble p_T) const
{
    return exp(-m_r * p_T);
}

OptionDouble Vanilla_BS_I_CallOption::call_delta(OptionDouble p_S) const
{
    return Utils::normal_cdf(calc_d1(p_S));
}

OptionDouble Vanilla_BS_I_CallOption::calculate_delta(OptionDouble p_S) const
{
    return call_delta(p_S);
}

OptionDouble Vanilla_BS_I_CallOption::calculate_gamma(OptionDouble p_S) const
{
    double pdf_d1 = Utils::normal_pdf(calc_d1(p_S));
    return pdf_d1 / (p_S * m_vol * m_sqrt_ttm);
}

OptionDouble Vanilla_BS_I_PutOption::price(OptionDouble p_S) const
{
    return price_call(p_S) + m_kert - p_S;
}

OptionDouble Vanilla_BS_I_PutOption::calculate_delta(OptionDouble p_S) const
{
    return 1. - call_delta(p_S);
}

void Vanilla_BS_I_CallOption::precalculate() 
{
    // precalculate some values we use a few times.
    m_var = m_vol * m_vol;
    m_sqrt_ttm = sqrt(m_ttm);
    m_kert = m_K * calculate_discount_factor(m_ttm);
}