#include <cmath>
#include <cassert>
#include <iostream>
#include <ios>
#include "vanilla_black_scholes_tests.hpp"
#include "../../vanilla_black_scholes/black_scholes_option.hpp"

bool Test_VanillaBlackScholes::basic_call_price_test() const
{
    VanillaBSEuropeanCall_Option option(10., 0.05, 0.4, 0.25);
    OptDouble test_val = option.price(10.);
    OptDouble desired_val = 0.855261;
    return abs(test_val - desired_val) < m_eps;
}

bool Test_VanillaBlackScholes::pde_call_test() const
{
    OptDouble desired_val = 0.855261;
    OptDouble test_val = VanillaBSEuropeanCallPDE_Option(10., 0.05, 0.4, 0.25).price(10.);
    return abs( (test_val - desired_val)  )< 10e-3;

}
bool Test_VanillaBlackScholes::basic_put_price_test() const
{
    VanillaBSEuropeanPut_Option option(10., 0.05, 0.4, 0.25);
    OptDouble test_val = option.price(10.);
    OptDouble desired_val = 0.731039;
    return abs(test_val - desired_val) < m_eps;
}

void Test_VanillaBlackScholes::run_all_tests() const
{
    std::cout << std::boolalpha;
    std :: cout << "Beginning basic Black Scholes tests:" << '\n';
    std::cout << "Vanilla call test: " << basic_call_price_test() << '\n';
    std::cout << "Vanilla put test: " << basic_put_price_test() << '\n';
    std::cout << "PDE call test: " << pde_call_test() << '\n';

}