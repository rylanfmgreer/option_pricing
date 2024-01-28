#include "utilities.hpp"
#include <gsl/gsl_vector.h>
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

    gsl_sp create_gsl_vector_from_std_vector( const std::vector<OptDouble> p_v)
    {
        gsl_sp vp( gsl_vector_alloc(p_v.size() ) );
        for(int i(0); i < p_v.size(); ++i )
            vp.get()[i] = p_v[i];
        return vp;
    }
    std::vector<OptDouble> create_std_vector_from_gsl_vector(const gsl_sp p_p)
    {
        std::vector<OptDouble> v(p_p->size());
        for( int i(0); i < p_p->size(); ++i  )
            v[i] = p_p.get()[i];
        return v;
    }
    
    std::vector<OptDouble> solve_tridiagonal_system(
        const std::vector<OptDouble> p_subdiagonal,
        const std::vector<OptDouble> p_diagonal,
        const std::vector<OptDouble> p_superdiagonal, 
        const std::vector<OptDouble> p_b)
    {
        gsl_sp subdiagonal = create_gsl_vector_from_std_vector(p_subdiagonal);
        gsl_sp diagonal = create_gsl_vector_from_std_vector(p_diagonal);
        gsl_sp superdiagonal = create_gsl_vector_from_std_vector(p_superdiagonal);
        gsl_sp b = create_gsl_vector_from_std_vector(p_b);
        gsl_sp x( gsl_vector_alloc(diagonal.size() ));
        gsl_linalg_solve_tridiag(diagonal.get(), superdiagonal.get(), subdiagonal.get(), b.get(), x.get());
        std::vector<OptDouble> v_x = create_std_vector_from_gsl_vector(x);
        return v_x;
    }

};