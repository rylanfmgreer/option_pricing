#ifndef _option_rg_8923892
#define _option_rg_8923892
#include <memory>
#include "i_option.hpp"


class Option
{
    public:
    virtual OptDouble price(OptDouble p_S);
    virtual OptDouble calculate_delta(OptDouble p_S);
    std::shared_ptr<I_Option> m_iopt;
};

#endif