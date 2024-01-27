#include "option.hpp"


OptionDouble Option::price(OptionDouble p_S)
{
    return m_iopt->price(p_S);
}