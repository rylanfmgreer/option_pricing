#include "black_scholes_option.hpp"
#include "implementations/black_scholes_ioption.hpp"

Vanilla_BS_CallOption::Vanilla_BS_CallOption(OptionDouble p_K, OptionDouble p_r,
            OptionDouble p_vol, OptionDouble p_ttm)
    {
        std::shared_ptr<Vanilla_BS_I_CallOption> this_ptr(
            new Vanilla_BS_I_CallOption(p_K, p_r, p_vol, p_ttm));
        m_iopt = this_ptr;
    }

Vanilla_BS_PutOption::Vanilla_BS_PutOption(OptionDouble p_K, OptionDouble p_r,
            OptionDouble p_vol, OptionDouble p_ttm)
    {
        std::shared_ptr<Vanilla_BS_I_PutOption> this_ptr(
            new Vanilla_BS_I_PutOption(p_K, p_r, p_vol, p_ttm));
        m_iopt = this_ptr;
    }