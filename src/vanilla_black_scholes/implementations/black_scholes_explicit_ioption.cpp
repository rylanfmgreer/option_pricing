#include "black_scholes_explicit_ioption.hpp"
#include <cmath>
#include <algorithm>

BlackScholesExplicit_I_Option::BlackScholesExplicit_I_Option(OptDouble p_K, OptDouble p_r, OptDouble p_vol, OptDouble p_ttm)
: m_K(p_K), m_vol(p_vol), m_r(p_r), m_ttm(p_ttm)
{
    m_max_price = 2. * m_K;
    m_ds = (m_max_price - m_min_price) / (double)((m_N_stock_points - 1));
    m_ds_sq = m_ds * m_ds;
    m_dt = p_ttm / (double)m_N_timesteps;
    m_var = m_vol * m_vol;
    initialize_terminal_stock_array();
    solve_pde();
    initialize_interpolation();
}

void BlackScholesExplicit_I_Option::initialize_interpolation()
{
    m_interpolation.reset(
        new CubicSplineInterpolation(m_stock_array, m_calc_array)
    );
}

OptDouble BlackScholesExplicit_I_Option::price(OptDouble p_S)
{
    return m_interpolation->interpolate(p_S);
}

OptDouble BlackScholesExplicit_I_Option::calculate_delta(OptDouble p_S)
{
    auto below = std::upper_bound(m_calc_array.begin(), m_calc_array.end(), p_S);
    auto above = below + 1;
    return (*above - *below) / m_ds;
}
OptDouble BlackScholesExplicit_I_Option::calculate_gamma(OptDouble p_S)
{
    auto mid = std::upper_bound(m_calc_array.begin(), m_calc_array.end(), p_S);
    OptDouble gam = ( *(mid+1) + *(mid-1) - 2.0 * (*mid));
    return gam / m_ds_sq;
}

OptDouble BlackScholesExplicit_I_Option::calculate_ci_term(int p_i)
{
    OptDouble scalar = (1. - m_r * m_dt);
    scalar -= (m_var * m_dt / m_ds_sq) * m_stock_sq_array[p_i];
    return scalar * m_calc_array[p_i];
}

OptDouble BlackScholesExplicit_I_Option::calculate_cip1_term(int p_i)
{
    OptDouble scalar = (m_r * m_dt / (2. * m_ds)) * m_stock_array[p_i];
    scalar += 0.5 * m_var * (m_dt / m_ds_sq) * m_stock_sq_array[p_i];
    return scalar * m_calc_array[p_i+1];
 }

OptDouble BlackScholesExplicit_I_Option::calculate_cim1_term(int p_i)
{
    OptDouble scalar = 0.5 * m_var * (m_dt / m_ds_sq) * m_stock_sq_array[p_i];
    scalar -= m_r * m_dt / (2. * m_ds) * m_stock_array[p_i];
    return scalar * m_calc_array[p_i-1];
}

OptDouble BlackScholesExplicit_I_Option::calc_opt_price_from_theta(int p_i)
{
    return (
        calculate_ci_term(p_i) + calculate_cim1_term(p_i) + calculate_cip1_term(p_i)
    );
}

void BlackScholesExplicit_I_Option::initialize_calculation_array()
{
    std::vector<OptDouble> v(m_N_stock_points, 0);
    std::transform(m_stock_array.begin(), m_stock_array.end(), v.begin(),
        [this] ( OptDouble x ){ return std::max<OptDouble>(x - this->m_K, 0. ); });
    m_calc_array = v;
}

void BlackScholesExplicit_I_Option::evolve_calc_array_backwards_by_one_timestep_explicit(int p_timestep)
{
    std::vector<OptDouble> new_calc_array(m_calc_array.size());
    for( int i(1); i < m_calc_array.size()-1; ++i )
        new_calc_array[i] = calc_opt_price_from_theta(i);
    
    // boundary coditions in stock-price space
    new_calc_array[0] = 0.;
    new_calc_array[new_calc_array.size() - 1] = (m_max_price - m_K) *  calculate_discount_factor((p_timestep + 1) * m_dt);

    m_calc_array = new_calc_array;
}

void BlackScholesExplicit_I_Option::solve_pde()
{
    initialize_calculation_array();
    for( int i(0); i < m_N_timesteps; ++i )
        evolve_calc_array_backwards_by_one_timestep_explicit(i);
}

void BlackScholesExplicit_I_Option::evolve_calc_array_backwards_by_one_timestep_implicit(int p_timestep)
{
}

void BlackScholesExplicit_I_Option::initialize_terminal_stock_array()
{
    std::vector<OptDouble> v(m_N_stock_points, 0);
    std::vector<OptDouble> vsq(m_N_stock_points, 0);

    std::transform(v.begin(), v.end() - 1, v.begin() + 1,
        [this] ( OptDouble x ){ return x + this->m_ds; });
    m_stock_array = v;

    std::transform(v.begin(), v.end(), vsq.begin(), 
        []( double x ){ return x * x; });
    m_stock_sq_array = vsq;
}