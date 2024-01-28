#include "option.hpp"


OptDouble Option::price(OptDouble p_S)
{
    return m_iopt->price(p_S);
}

OptDouble Option::calculate_delta(OptDouble p_S)
{
    return m_iopt->calculate_delta(p_S);
}
