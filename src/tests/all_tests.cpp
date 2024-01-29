#include "all_tests.hpp"
#include "vanilla_black_scholes/vanilla_black_scholes_tests.hpp"
#include "utility_tests/utility_tests.hpp"
#include "american_option/american_option_tests.hpp"

void AllTests::run_all_tests() const
{
    Test_Utilities().run_all_tests();
    Test_VanillaBlackScholes().run_all_tests();
    Test_AmericanaBlackScholes().run_all_tests();
}