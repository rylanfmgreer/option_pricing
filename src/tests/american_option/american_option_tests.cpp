#include "american_option_tests.hpp"
#include "../../american_option/american_option.hpp"
#include <iostream>

void Test_AmericanaBlackScholes::run_all_tests() const
{
    std::cout << "American option basic call test: " <<  basic_call_price_test() << std::endl;
    std::cout << "American option basic put test: " <<  basic_put_price_test() << std::endl;

}

bool Test_AmericanaBlackScholes::basic_call_price_test() const
{
    AmericanCallOption option(10., 0.4, 0.05, 0.25, 1000);
    OptDouble test_val = option.price(10.);
    OptDouble desired_val = 0.8550754509271077;
    return abs(test_val - desired_val) < 1e-4;
}

bool Test_AmericanaBlackScholes::basic_put_price_test() const
{
    AmericanPutOption option(10., 0.4, 0.05, 0.25, 1000);
    OptDouble test_val = option.price(10.);
    OptDouble desired_val = 0.740784946763085;
    return abs(test_val - desired_val) < 1e-3;
}