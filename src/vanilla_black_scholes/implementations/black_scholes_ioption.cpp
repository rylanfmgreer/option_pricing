#include <cmath>
#include "black_scholes_ioption.hpp"
#include "../../utilities/utilities.hpp"

VanillaBSEuropeanCall_I_Option::VanillaBSEuropeanCall_I_Option(
    OptDouble p_K, OptDouble p_r,
    OptDouble p_vol, OptDouble p_ttm)
    :m_K(p_K), m_r(p_r), m_vol(p_vol), m_ttm(p_ttm)
{
        precalculate();
}


OptDouble VanillaBSEuropeanCall_I_Option::price(OptDouble p_S)
{
    return price_call(p_S);
}


OptDouble VanillaBSEuropeanCall_I_Option::price_call(OptDouble p_S) const
{
    OptDouble d1 = calc_d1(p_S);
    OptDouble d2 = calc_d2(d1);
    boost::math::normal new_normal;
    return (p_S * Utils::normal_cdf(d1, &new_normal)
        - m_kert * Utils::normal_cdf(d2, &new_normal) );
}


OptDouble VanillaBSEuropeanCall_I_Option::calc_d1(OptDouble p_S) const
{
    OptDouble lnsk = log(p_S / m_K);
    OptDouble rsigt = (m_r +  0.5 * m_var) * m_ttm;
    return (lnsk + rsigt) / (m_vol * m_sqrt_ttm);

}


OptDouble VanillaBSEuropeanCall_I_Option::calc_d2(OptDouble p_d1) const
{
    return p_d1 - m_vol * m_sqrt_ttm;
}


OptDouble VanillaBSEuropeanCall_I_Option::calculate_discount_factor(OptDouble p_T) const
{
    return exp(-m_r * p_T);
}

OptDouble VanillaBSEuropeanCall_I_Option::call_delta(OptDouble p_S) const
{
    return Utils::normal_cdf(calc_d1(p_S));
}

OptDouble VanillaBSEuropeanCall_I_Option::calculate_delta(OptDouble p_S)
{
    return call_delta(p_S);
}

OptDouble VanillaBSEuropeanCall_I_Option::calculate_gamma(OptDouble p_S)
{
    double pdf_d1 = Utils::normal_pdf(calc_d1(p_S));
    return pdf_d1 / (p_S * m_vol * m_sqrt_ttm);
}

OptDouble VanillaBSEuropeanPut_I_Option::price(OptDouble p_S)
{
    return price_call(p_S) + m_kert - p_S;
}

OptDouble VanillaBSEuropeanPut_I_Option::calculate_delta(OptDouble p_S)
{
    return 1. - call_delta(p_S);
}

void VanillaBSEuropeanCall_I_Option::precalculate() 
{
    // precalculate some values we use a few times.
    m_var = m_vol * m_vol;
    m_sqrt_ttm = sqrt(m_ttm);
    m_kert = m_K * calculate_discount_factor(m_ttm);
}