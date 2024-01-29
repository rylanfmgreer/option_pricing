#include "american_option.hpp"

AmericanOption::AmericanOption(OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r, OptDouble p_T, int p_n_timesteps)
        :m_iopt( new AmericanTree_I_Option(p_K, p_vol, p_r, p_T, p_n_timesteps) )
        {}