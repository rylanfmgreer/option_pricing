#ifndef _utility_tests_832948293
#define _utility_tests_832948293

class Test_Utilities
{
    public:
    void run_all_tests() const;
    bool test_normal_cdf() const;
    bool test_normal_pdf() const;
    bool test_to_array() const;
    bool test_interpolation() const;
    bool test_gsl_tridiag() const;

    private:
    double m_eps = 1e-4;

};
#endif
