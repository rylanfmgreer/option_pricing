#include <algorithm>
#include <cmath>
#include "interpolation.hpp"
#include "utilities.hpp"

Interpolation::Interpolation(const std::vector<OptDouble> p_known_x,
    const std::vector<OptDouble> p_known_y, 
    const gsl_interp_type* p_interp_type
)
: m_x_array( Utils::vector_to_array(p_known_x) ),
  m_y_array( Utils::vector_to_array(p_known_y) ),
  m_interp( gsl_interp_alloc(p_interp_type, p_known_x.size()), &gsl_interp_free ),
  m_interp_accel( gsl_interp_accel_alloc(), &gsl_interp_accel_free )
  {
    gsl_interp_init(m_interp.get(), m_x_array.get(), m_y_array.get(), p_known_x.size());
  }
  
double Interpolation::interpolate(OptDouble p_x) const
{
    return  gsl_interp_eval(m_interp.get(),
        m_x_array.get(), m_y_array.get(), p_x, m_interp_accel.get());
}