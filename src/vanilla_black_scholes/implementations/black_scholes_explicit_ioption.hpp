#ifndef _black_scholes_explicit_i_option_398294
#define _black_scholes_explicit_i_option_398294
#include <vector>
#include "../../i_option.hpp"
#include "../black_scholes_option.hpp"
#include "../../utilities/interpolation.hpp"

class BlackScholesExplicit_I_Option: public I_Option
{
    public:
    virtual OptDouble calculate_discount_factor(OptDouble p_T) const { return exp(-m_r * p_T); }

    friend class VanillaBSEuropeanCall_Option;
    friend class VanillaBSEuropeanCallPDE_Option;
    friend class VanillaBSEuropeanPut_Option;

    protected:
    BlackScholesExplicit_I_Option(OptDouble p_K, OptDouble p_r, OptDouble p_vol, OptDouble p_ttm);

    virtual OptDouble price(OptDouble p_S) const;
    virtual OptDouble calculate_delta(OptDouble p_S) const;
    virtual OptDouble calculate_gamma(OptDouble p_S) const;

    private:
    std::function<OptDouble (OptDouble)> m_boundary_condition;
    std::unique_ptr<CubicSplineInterpolation> m_interpolation;
    void initialize_interpolation();
    // hardcoded for now... TODO fix!
    unsigned int m_N_timesteps = 2000;
    unsigned int m_N_stock_points = 200;

    // the things we save down
    OptDouble m_K;
    OptDouble m_vol;
    OptDouble m_r;
    OptDouble m_ttm;

    // things we calculate fairly quickly from the other variables
    OptDouble m_var;
    OptDouble m_dt;
    OptDouble m_ds;
    OptDouble m_ds_sq;
    OptDouble m_min_price = 0.;
    OptDouble m_max_price;

    // pde solving
    void initialize_calculation_array();
    std::vector<OptDouble> m_calc_array;

    void initialize_terminal_stock_array();
    std::vector<OptDouble> m_stock_array;
    std::vector<OptDouble> m_stock_sq_array;

    OptDouble calculate_ci_term(int i);
    OptDouble calculate_cim1_term(int i);
    OptDouble calculate_cip1_term(int i);
    OptDouble calc_opt_price_from_theta(int i);
    void evolve_calc_array_backwards_by_one_timestep_explicit(int p_timestep);
    void evolve_calc_array_backwards_by_one_timestep_implicit(int p_timestep);
    void solve_pde();



};

#endif