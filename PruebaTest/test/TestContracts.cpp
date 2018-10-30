//
// Created by carlos on 26/10/18.
//
#define BOOST_TEST_MODULE NTCALCWC_SUITE
#include <boost/test/unit_test.hpp>
#include <boost/contract.hpp>
#include <boost/test/data/test_case.hpp>
#include "../src/NumberTheoryCalculatorWithContracts.h"

namespace bdata = boost::unit_test::data;

struct F {
    F() : i( 0 ) { boost::contract::set_precondition_failure(
                boost::contract::set_postcondition_failure(
                        boost::contract::set_invariant_failure(
                                boost::contract::set_old_failure(
                                        [] (boost::contract::from where) {
                                            if(where == boost::contract::from_destructor) {
                                                // Shall not throw from C++ destructors.
                                                std::clog << "ignored destructor contract failure" << std::endl;
                                            } else throw; // Re-throw (assertion_failure, user-defined, etc.).
                                        }
                                ))));
        boost::contract::set_except_failure(
                [] (boost::contract::from where) {
                    // Already an active exception so shall not throw another...
                    std::clog << "ignored exception guarantee failure" << std::endl;
                }
        );
        boost::contract::set_check_failure(
                [] {
                    // But now CHECK shall not be used in destructor implementations.
                    throw; // Re-throw (assertion_failure, user-defined, etc.).
                }
        ); }
    ~F()         { BOOST_TEST_MESSAGE( "teardown global fixture" ); }

    int i;
};

BOOST_GLOBAL_FIXTURE(F);

BOOST_AUTO_TEST_SUITE(number_theory_with_contracts_suite)

    const int sign_params[] = {0, 5, -10};
    const int sign_results[] = {0, 1, -1};

    BOOST_DATA_TEST_CASE(parametrized_sign_test, bdata::make(sign_params)^sign_results, entero, signo_esperado)
    {
        // ARRANGE
        NumberTheoryCalculatorWithContracts calc;

        // ACT
        int signo = calc.signo(entero);

        // ASSERT
    BOOST_CHECK_EQUAL(signo, signo_esperado);
    }

    BOOST_AUTO_TEST_CASE(check_incorrect_precondition_div)
    {
        NumberTheoryCalculatorWithContracts calc;
        int a = 15;
        int b = -4;

        BOOST_CHECK_THROW(calc.div(a,b), boost::contract::assertion_failure);
    }

    const int div_params1[] = {20, -53};
    const int div_params2[] = {3, 1, 50};

    BOOST_DATA_TEST_CASE(parametrized_div_test, (bdata::make(div_params1)*div_params2), dividendo, divisor)
    {
        // ARRANGE
        NumberTheoryCalculatorWithContracts calc;

        // ACT
        int cociente = calc.div(dividendo, divisor);
        int resto = calc.mod(dividendo, divisor);

        // ASSERT
        BOOST_CHECK_EQUAL(resto, dividendo - divisor * cociente);
    }

    const int mcd_params1[] = {20, 53, 0};
    const int mcd_params2[] = {5, 1, 64};

    BOOST_DATA_TEST_CASE(parametrized_mcd_test, (bdata::make(mcd_params1)*mcd_params2), x1, x2)
    {
        // ARRANGE
        NumberTheoryCalculatorWithContracts calc;

        // ACT
        int mcd = calc.mcd(x1, x2);

        // ASSERT
        BOOST_CHECK(calc.divisible(x1, mcd) && calc.divisible(x2,mcd)); // weak postcondition
    }

    const int mcm_params1[] = {20, 53, 77};
    const int mcm_params2[] = {5, 1, 64};

    BOOST_DATA_TEST_CASE(parametrized_mcm_test, (bdata::make(mcm_params1)*mcm_params2), x1, x2)
    {
        // ARRANGE
        NumberTheoryCalculatorWithContracts calc;

        // ACT
        int mcm = calc.mcm(x1, x2);

        // ASSERT
        BOOST_CHECK(calc.divisible(mcm, x1) && calc.divisible(mcm, x2)); // weak postcondition
    }

    BOOST_AUTO_TEST_CASE(check_incorrect_precondition_mcd)
    {
        NumberTheoryCalculatorWithContracts calc;
        int a = 0;
        int b = 0;

        BOOST_CHECK_THROW(calc.mcd(a,b), boost::contract::assertion_failure);
    }

    BOOST_AUTO_TEST_CASE(check_incorrect_precondition_mcm)
    {
        NumberTheoryCalculatorWithContracts calc;
        int a = 0;
        int b = 0;

        BOOST_CHECK_THROW(calc.mcm(a,b), boost::contract::assertion_failure);
    }

BOOST_AUTO_TEST_SUITE_END()