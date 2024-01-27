#include "black_scholes_option.hpp"
#include "implementations/black_scholes_ioption.hpp"
#include "implementations/black_scholes_explicit_ioption.hpp"

VanillaBSEuropeanCall_Option::VanillaBSEuropeanCall_Option(OptDouble p_K, OptDouble p_r,
            OptDouble p_vol, OptDouble p_ttm)
    {
        std::shared_ptr<VanillaBSEuropeanCall_I_Option> this_ptr(
            new VanillaBSEuropeanCall_I_Option(p_K, p_r, p_vol, p_ttm));
        m_iopt = this_ptr;
    }

OptDouble VanillaBSEuropeanCall_Option::calculate_delta(OptDouble p_S) const
{
    return m_iopt->calculate_delta(p_S);
}

OptDouble VanillaBSEuropeanCall_Option::calculate_gamma(OptDouble p_S) const
{
    return m_iopt->calculate_delta(p_S);
}

VanillaBSEuropeanCallPDE_Option::VanillaBSEuropeanCallPDE_Option(OptDouble p_K, OptDouble p_r,
            OptDouble p_vol, OptDouble p_ttm)
{
    std::shared_ptr<BlackScholesExplicit_I_Option> this_ptr(
        new BlackScholesExplicit_I_Option(p_K, p_r, p_vol, p_ttm)
    );
    m_iopt = this_ptr;
}
VanillaBSEuropeanPut_Option::VanillaBSEuropeanPut_Option(OptDouble p_K, OptDouble p_r,
            OptDouble p_vol, OptDouble p_ttm)
    {
        std::shared_ptr<VanillaBSEuropeanPut_I_Option> this_ptr(
            new VanillaBSEuropeanPut_I_Option(p_K, p_r, p_vol, p_ttm));
        m_iopt = this_ptr;
    }