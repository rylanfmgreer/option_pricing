#include "src/tests/all_tests.hpp"
#include "src/vanilla_black_scholes/black_scholes_option.hpp"
#include <iostream>
int main()
{
     VanillaBSEuropeanCallPDE_Option opt(10., 0.1, 0.4, 0.25);
     std::cout << opt.price(10.000) << std::endl;
     AllTests().run_all_tests();
}