#include "all_tests.hpp"
#include "vanilla_black_scholes/vanilla_black_scholes_tests.hpp"

void AllTests::run_all_tests() const
{
    Test_VanillaBlackScholes().run_all_tests();
}