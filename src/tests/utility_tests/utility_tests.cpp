#include <iostream>
#include <cmath>
#include "utility_tests.hpp"
#include "../../utilities/utilities.hpp"
#include "../../utilities/gsl_interface/gsl_interface.hpp"
#include "../../utilities/interpolation.hpp"

void Test_Utilities::run_all_tests() const
{
    std::cout << std::boolalpha;
    std::cout << "Beginning utilities test" << '\n';
    std::cout << "Normal CDF test: " << test_normal_cdf() << '\n';
    std::cout << "Normal PDF test: " << test_normal_cdf() << '\n';
    std::cout << "Array test: " << test_normal_cdf() << '\n';
    std::cout << "Interpolation test: " << test_normal_cdf() << '\n';
    std::cout << "GSL Tridiag test: " << test_gsl_tridiag() << '\n';

    std::cout << '\n';

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

bool Test_Utilities::test_interpolation() const
{
    std::vector<double> x{0, 1};
    std::vector<double> y{3, 5};
    return abs(Sorted_Interpolation().interpolate(0.5, x, y) - 4.0) < m_eps;

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

bool Test_Utilities::test_gsl_tridiag() const
{
    std::vector<OptDouble> subdiagonal(5, 2);
    std::vector<OptDouble> diagonal(6, 1);
    std::vector<OptDouble> superdiagonal(5, 3);
    std::vector<OptDouble> b(6, 1);

    std::vector<OptDouble> x = Utils::solve_tridiagonal_system(subdiagonal, diagonal, superdiagonal, b);
    return  abs(x[4] - 0.9655172413793) < 1e-8;


}