#include <iostream>
#include <cmath>
#include "utility_tests.hpp"
#include "../../utilities/utilities.hpp"

void Test_Utilities::run_all_tests() const
{
    std::cout << std::boolalpha;
    std::cout << "Normal CDF test: " << test_normal_cdf() << '\n';
    std::cout << "Normal PDF test: " << test_normal_cdf() << '\n';
    std::cout << "Array test: " << test_normal_cdf() << '\n';

}

bool Test_Utilities::test_normal_cdf() const
{
    double _x = 0.7;
    double _y = 0.7580;
    return (abs(Utils::normal_cdf(_x) - _y) < m_eps);
}

bool Test_Utilities::test_normal_pdf() const
{
    double _x = 0.55;
    double _y = 0.34294386;
    return (abs(Utils::normal_pdf(_x) - _y) < m_eps);
}

bool Test_Utilities::test_to_array() const
{
    std::vector<int> v{2, 4, 6, 8};
    int* arr = Utils::vector_to_array(v);
    bool ret_this = true;
    if(arr[2] != 6)
        ret_this = false;
    delete[] arr;
    return ret_this;
}