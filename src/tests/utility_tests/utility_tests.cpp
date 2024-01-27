#include <iostream>
#include <cmath>
#include "utility_tests.hpp"
#include "../../utilities/utilities.hpp"

void Test_Utilities::run_all_tests() const
{
    std::cout << std::boolalpha;
    std::cout << "Normal CDF test: " << test_normal_cdf() << '\n';

}

bool Test_Utilities::test_normal_cdf() const
{
    double _x = 0.7;
    double _y = 0.7580;
    return (abs(Utils::normal_cdf(_x) - _y) < m_eps);
}