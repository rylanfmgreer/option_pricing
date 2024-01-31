
#include "gsl_interface.hpp"
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_complex.h>
#include "../utilities.hpp"

namespace Utils
{
    void GslUP::set_value(int i, OptDouble v)
    {
        gsl_vector_set(get(), i, v);
    }

    GslUP::GslUP(const std::vector<OptDouble> p_v)
    : GslUP(p_v.size())
    {
        for(int i(0); i < p_v.size(); ++i)
            set_value(i, p_v[i]);
    }

    std::vector<OptDouble> GslUP::to_vector() const
    {
        return create_std_vector_from_gsl_vector(*this);
    }

    OptDouble GslUP::get_value(int i) const
    {
        return gsl_vector_get(get(), i);
    }

    GslUP create_gsl_vector_of_size_n(int n)
    {
        return GslUP(n);
    }

    GslUP create_gsl_vector_from_std_vector( const std::vector<OptDouble>& p_v)
    {
       return GslUP(p_v);
    }
    
    std::vector<OptDouble> create_std_vector_from_gsl_vector(const GslUP& p_p)
    {
        int n = p_p->size;
        std::vector<OptDouble> v(n);
        for( int i(0); i < n; ++i  )
            v[i] = p_p.get_value(i);
        return v;
    }
    
    std::vector<OptDouble> solve_tridiagonal_system(
        const std::vector<OptDouble> p_subdiagonal,
        const std::vector<OptDouble> p_diagonal,
        const std::vector<OptDouble> p_superdiagonal, 
        const std::vector<OptDouble> p_b)
    {
        GslUP subdiagonal(p_subdiagonal);
        GslUP diagonal(p_diagonal);
        GslUP superdiagonal(p_superdiagonal);
        GslUP b(p_b);
        GslUP x(p_b.size());
        gsl_linalg_solve_tridiag(diagonal, superdiagonal, subdiagonal, b, x);
        std::vector<OptDouble> v_x = x.to_vector();
        return v_x;
    }


};