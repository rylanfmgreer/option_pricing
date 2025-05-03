#ifndef gsl_interface_3984728374928749
#define gsl_interface_3984728374928749
#include <vector>
#include <gsl/gsl_vector.h>
#include "../../consts.hpp"
#include "../complex/complex.hpp"

typedef std::unique_ptr<OptDouble[]> Double_arr_ptr;

namespace Utils
{
    /*
        An unique_ptr to a GSL Vector with some useful additions.
    */
    typedef std::unique_ptr<gsl_vector, decltype(&gsl_vector_free)> _GslUP;
    class GslUP : public _GslUP
    {
        public:
        using _GslUP::_GslUP;
        /*
            Initialize with n spaces.
        */
        GslUP(int n=0) : _GslUP(gsl_vector_alloc(n), &gsl_vector_free) {}

        /*
            Initialize with a vector
        */
        GslUP(const std::vector<OptDouble>& p_v);

        /*
            Set value at index p_i to p_v
        */
        void set_value(int p_i, OptDouble p_v);

        /*
            return the value at p_i
        */
        OptDouble get_value(int p_i) const;

        /*
            Turn this into an std::vector
        */
        std::vector<OptDouble> to_vector() const;

        /*
            Convert to a raw ptr
        */
        operator gsl_vector*() const { return get(); }
    };
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
        const std::vector<OptDouble>& p_subdiagonal,
        const std::vector<OptDouble>& p_diagonal,
        const std::vector<OptDouble>& p_superdiagonal, 
        const std::vector<OptDouble>& p_b);

    std::vector<Complex> fft(const std::vector<Complex>& p_v);
    double* unpack_complex_vector_into_complex_array(const std::vector<Complex>& p_v);

}



  

#endif
