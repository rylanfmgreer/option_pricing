#ifndef gsl_interface_3984728374928749
#define gsl_interface_3984728374928749
#include <vector>
#include <gsl/gsl_vector.h>
#include "../../consts.hpp"

namespace Utils
{
    auto del_GslUP = [](gsl_vector* p) { gsl_vector_free(p); };
    typedef std::unique_ptr<gsl_vector, decltype(del_GslUP) > GslUP;
    GslUP create_gsl_vector_of_size_n(int n);
    GslUP create_gsl_vector_from_std_vector( const std::vector<OptDouble>& p_v);
    std::vector<OptDouble> create_std_vector_from_gsl_vector(const GslUP& p_p);
    std::vector<OptDouble> solve_tridiagonal_system(
        const std::vector<OptDouble> p_subdiagonal,
        const std::vector<OptDouble> p_diagonal,
        const std::vector<OptDouble> p_superdiagonal, 
        const std::vector<OptDouble> p_b);
}

#endif