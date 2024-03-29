#ifndef _american_option_hjdhf0983y49huio2
#define _american_option_hjdhf0983y49huio2
#include "../option.hpp"
#include "implementations/american_ioption_tree.hpp"

class AmericanOption : public Option
{
    public:
    AmericanOption(OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r, OptDouble p_T, int p_n_timesteps, 
        bool p_is_call=true);
    std::unique_ptr<AmericanTree_I_Option> m_iopt;
    virtual OptDouble price( OptDouble p_S) const { return m_iopt->price(p_S); }

    friend class AmericanCallOption;
    friend class AmericanPutOption;
};

class AmericanCallOption: public AmericanOption
{
    public:
    AmericanCallOption(OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r, OptDouble p_T, int p_n_timesteps);
    std::unique_ptr<AmericanTree_I_Option> m_iopt;

};

class AmericanPutOption: public AmericanOption
{
    public:
    AmericanPutOption(OptDouble p_K, 
        OptDouble p_vol, OptDouble p_r, OptDouble p_T, int p_n_timesteps);
    std::unique_ptr<AmericanTree_I_Option> m_iopt;

};

#endif