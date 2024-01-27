#include "option.hpp"


OptDouble Option::price(OptDouble p_S)
{
    return m_iopt->price(p_S);
}