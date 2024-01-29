#ifndef _american_ioption_tree_jkdsnoahfo
#define _american_ioption_tree_jkdsnoahfo
#include "../../i_option.hpp"
#include <vector>

class AmericanTree_I_Option : public I_Option
{
    public:
    AmericanTree_I_Option(OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r, OptDouble p_T, int p_n_timesteps);
    virtual OptDouble price(OptDouble p_S);
    virtual OptDouble calculate_discount_factor(OptDouble p_T) const { return exp(-m_r * p_T); }
    virtual OptDouble calculate_delta(OptDouble p_T){ return 0.0; }
    virtual OptDouble calculate_gama(OptDouble x){ return 0.0; }

    private:
    typedef std::vector<OptDouble> odv;
    odv m_prices;
    std::vector< odv > m_stock_vectors;
    void create_stock_price_array();
    void create_final_timestep();
    void evolve_array_backwards(int i);
    void calculate_continuation_values();
    void calculate_best_of_continuation_vs_stock(int i);
    void compute_pricing();
    
    OptDouble m_S0;
    OptDouble m_K;
    OptDouble m_vol;
    OptDouble m_r;
    OptDouble m_T;


    OptDouble m_dt;
    OptDouble m_up_factor;
    OptDouble m_down_factor;
    OptDouble m_rnp_up;
    OptDouble m_rnp_down;
    OptDouble m_discount_factor;
    odv m_continuation_values;

    size_t m_n_timesteps;
};
#endif  