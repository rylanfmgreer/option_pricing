#include "american_option.hpp"

AmericanOption::AmericanOption(OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r, OptDouble p_T,
        int p_n_timesteps, bool p_is_call)
        :m_iopt( new AmericanTree_I_Option(p_K, p_vol,
            p_r, p_T, p_n_timesteps, p_is_call) )
        {}

AmericanCallOption::AmericanCallOption(OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r,
        OptDouble p_T, int p_n_timesteps)
        :AmericanOption(p_K, p_vol, p_r, p_T, p_n_timesteps, true){}

AmericanPutOption::AmericanPutOption(OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r,
        OptDouble p_T, int p_n_timesteps)
        :AmericanOption(p_K, p_vol, p_r, p_T, p_n_timesteps, false){}

