#ifndef _vanilla_black_scholes_tests_rg_39847230
#define _vanilla_black_scholes_tests_rg_39847230

class Test_VanillaBlackScholes
{
    public:
    bool basic_call_price_test() const;
    bool basic_put_price_test() const;
    bool pde_call_test() const;
    void run_all_tests() const;

    private:
    double m_eps = 1e-5;
};

#endif