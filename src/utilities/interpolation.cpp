#include <algorithm>
#include <cmath>
#include "interpolation.hpp"
#include "utilities.hpp"

Interpolation::Interpolation(const std::vector<OptDouble> p_known_x, const std::vector<OptDouble> p_known_y)
: m_xa( Utils::vector_to_array(p_known_x) ), m_ya( Utils::vector_to_array(p_known_y) ),
  m_interp( gsl_interp_alloc(gsl_interp_linear, p_known_x.size()), &gsl_interp_free ),
  m_interp_accel(gsl_interp_accel_alloc(), &gsl_interp_accel_free)
  {
    gsl_interp_init(m_interp.get(), m_xa.get(), m_ya.get(), p_known_x.size());
  }
  
double Interpolation::interpolate(OptDouble p_x) const
{
    return  gsl_interp_eval(m_interp.get(), m_xa.get(), m_ya.get(), p_x, m_interp_accel.get());
}