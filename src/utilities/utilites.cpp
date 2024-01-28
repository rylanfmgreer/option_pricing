#include "utilities.hpp"
#include <gsl/gsl_linalg.h>

namespace Utils
{
    double normal_pdf(double p_z, boost::math::normal* p_dist)
    {
        if(p_dist == nullptr)
        {
            boost::math::normal new_normal;
            p_dist = &new_normal;
        }
        return boost::math::pdf(*p_dist, p_z);

    }
    
    double normal_cdf(double p_z, boost::math::normal* p_dist)
    {
        if(p_dist == nullptr)
        {
            boost::math::normal new_normal;
            p_dist = &new_normal;
        }
        return boost::math::cdf(*p_dist, p_z);
    }

    GslUP create_gsl_vector_from_std_vector( const std::vector<OptDouble>& p_v)
    {
        GslUP vp( gsl_vector_alloc(p_v.size() ), del_GslUP);
        for(int i(0); i < p_v.size(); ++i )
            gsl_vector_set(vp.get(), i, p_v[i]);
        return vp;
    }
    std::vector<OptDouble> create_std_vector_from_gsl_vector(const GslUP& p_p)
    {
        int n = p_p->size;
        std::vector<OptDouble> v(n);
        for( int i(0); i < n; ++i  )
            v[i] = gsl_vector_get(p_p.get(), i);
        return v;
    }
    
    std::vector<OptDouble> solve_tridiagonal_system(
        const std::vector<OptDouble> p_subdiagonal,
        const std::vector<OptDouble> p_diagonal,
        const std::vector<OptDouble> p_superdiagonal, 
        const std::vector<OptDouble> p_b)
    {
        GslUP subdiagonal = create_gsl_vector_from_std_vector(p_subdiagonal);
        GslUP diagonal = create_gsl_vector_from_std_vector(p_diagonal);
        GslUP superdiagonal = create_gsl_vector_from_std_vector(p_superdiagonal);
        GslUP b = create_gsl_vector_from_std_vector(p_b);
        GslUP x( gsl_vector_alloc(p_diagonal.size()), del_GslUP);
        gsl_linalg_solve_tridiag(diagonal.get(), superdiagonal.get(),
            subdiagonal.get(), b.get(), x.get());
        std::vector<OptDouble> v_x = create_std_vector_from_gsl_vector(x);
        return v_x;
    }

};