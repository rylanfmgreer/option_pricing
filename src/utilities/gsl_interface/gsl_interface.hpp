#ifndef gsl_interface_3984728374928749
#define gsl_interface_3984728374928749
#include <vector>
#include <gsl/gsl_vector.h>
#include "../../consts.hpp"

namespace Utils
{
    /*
        Typedef for a GSL vector unique pointer so that
        we have better resource mgmt.
    */
    auto del_GslUP = [](gsl_vector* p) { gsl_vector_free(p); };
    typedef std::unique_ptr<gsl_vector, decltype(del_GslUP) > GslUP;

    /*
        Create an empty GslUP of size n

        :param p_n: how many entries to include
        :return: GslUP initialized with size p_n
    */
    GslUP create_gsl_vector_of_size_n(int p_n);

    /*
        Convert a std::vector into a GslUP

        :param p_v: vector to convert
        :return: GslUP with entries the same as p_v
    */
    GslUP create_gsl_vector_from_std_vector( const std::vector<OptDouble>& p_v);

    /*
        Convert a GslUP into a std::vector

        :param p_GslUP: the vector to convert
        :return: an std::vector with the same entries
    */
    std::vector<OptDouble> create_std_vector_from_gsl_vector(const GslUP& p_GslUP);

    /*
        Solve a tridiagonal system.

        Consider the matrix equation Ax=b
        where A is tridiagonal.

        :param p_subdiagonal: the entries of A below the diagonal
        :param p_diagonal: the entries of A on the diagonal
        :param p_superdiagonal: the entries of A above the diagonal
        :param p_b: the 'b' in the matrix expression
        :return: the 'x' in the matrix expression
    */
    std::vector<OptDouble> solve_tridiagonal_system(
        const std::vector<OptDouble> p_subdiagonal,
        const std::vector<OptDouble> p_diagonal,
        const std::vector<OptDouble> p_superdiagonal, 
        const std::vector<OptDouble> p_b);
}

#endif