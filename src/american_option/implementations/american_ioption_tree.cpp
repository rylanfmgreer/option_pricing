#include "american_ioption_tree.hpp"
#include "../../consts.hpp"
#include <cmath>
AmericanTree_I_Option::AmericanTree_I_Option(OptDouble p_S0, OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r, OptDouble p_T, int p_n_timesteps)
        : m_S0(p_S0), m_K(p_K), m_vol(p_vol), m_r(p_r), m_T(p_T), m_n_timesteps(p_n_timesteps)
        {
            m_dt = m_T / (double)m_n_timesteps;
            m_discount_factor = calculate_discount_factor(m_dt);

            m_up_factor = exp(m_dt * m_vol);
            m_down_factor = exp(-m_dt * m_vol);
            m_rnp_up = (m_r - m_down_factor) / (m_up_factor - m_down_factor);
            m_rnp_down = 1. - m_rnp_up;
            m_rnp_up = m_discount_factor * m_rnp_up;
            m_rnp_down = m_discount_factor * m_rnp_down;
            compute_pricing();
        }

void AmericanTree_I_Option::compute_pricing()
{
    create_stock_price_array();
    create_final_timestep();
    for( int i(m_n_timesteps); i < 0; --i)
        evolve_array_backwards(i);
}

void AmericanTree_I_Option::create_stock_price_array()
{
    odv this_stock_vector(1, m_S0);
    m_stock_vectors.push_back(this_stock_vector);
    for(size_t i(2); i < m_n_timesteps + 1; ++i)
    {
        odv new_stock_vector(i);
        std::transform(this_stock_vector.begin(), this_stock_vector.end(),
            new_stock_vector.begin() + 1, 
            [this]( double s){ return s * this->m_up_factor;});
        new_stock_vector[0] = this_stock_vector[0] * m_down_factor;
        m_stock_vectors.push_back(new_stock_vector);
        this_stock_vector = new_stock_vector;
    }
    
}
void AmericanTree_I_Option::create_final_timestep()
{

    odv new_vector(m_n_timesteps + 1);
    odv final_stock_vector = m_stock_vectors.back();
    std::transform(final_stock_vector.begin(), final_stock_vector.end(), 
        new_vector.begin(), [this]( double x )
        { return std::max(x - this->m_K, 0.); });

    m_prices = new_vector;
}

void AmericanTree_I_Option::evolve_array_backwards(int i)
{
    calculate_continuation_values();
    calculate_best_of_continuation_vs_stock(i);
}

void AmericanTree_I_Option::calculate_continuation_values()
{
    odv continuation_values(m_prices.size() - 1);
    std::transform(m_prices.begin(), m_prices.end()-1,
        m_prices.begin() + 1, continuation_values.begin(),
        [this]( OptDouble down_val, OptDouble up_val)
        {
            return this->m_rnp_down * down_val + this->m_rnp_up * up_val;

        });
    m_continuation_values = continuation_values;
}

void AmericanTree_I_Option::calculate_best_of_continuation_vs_stock(int i)
{
    odv this_stock_vector = m_stock_vectors[m_stock_vectors.size() - i - 1];
    odv new_prices(m_continuation_values.size());
    std::transform(m_continuation_values.begin(), m_continuation_values.end(), 
        this_stock_vector.begin(), new_prices.begin(),
        [this](OptDouble cv, OptDouble S)
        {
            return std::max(cv, S - this->m_K);
        });
}