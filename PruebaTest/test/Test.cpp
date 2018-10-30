//
// Created by carlos on 19/10/18.
//

//#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE NTCALC_SUITE
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include "../src/NumberTheoryCalculator.h"
//#include <boost/test/included/unit_test.hpp>

namespace bdata = boost::unit_test::data;


BOOST_AUTO_TEST_SUITE(number_theory_suite)


const int sign_params[] = {0, 5, -10};
const int sign_results[] = {0, 1, -1};

    BOOST_DATA_TEST_CASE(parametrized_sign_test, bdata::make(sign_params)^sign_results, entero, signo_esperado)
    {
        // ARRANGE
        NumberTheoryCalculator calc;

        // ACT
        int signo = calc.signo(entero);

        // ASSERT
        BOOST_CHECK_EQUAL(signo, signo_esperado);
    }

    BOOST_AUTO_TEST_CASE(check_correct_div_positive_positive)
    {
        NumberTheoryCalculator calc;
        int a = 15;
        int b = 4;

        BOOST_CHECK_EQUAL(calc.div(a,b), 3);
    }

    BOOST_AUTO_TEST_CASE(check_correct_div_negative_positive)
    {
        NumberTheoryCalculator calc;
        int a = -15;
        int b = 4;

        int toTest = calc.div(a,b);
        int correctAnswer = a/b - 1;

        BOOST_CHECK_EQUAL(toTest, correctAnswer);
    }

    BOOST_AUTO_TEST_CASE(check_incorrect_div)
    {
        // ARRANGE
        NumberTheoryCalculator calc;
        int a = 15;
        int b = -4;

        // ASSERT
        BOOST_CHECK_THROW(calc.div(a,b), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(check_division_by_zero)
    {
        // ARRANGE
        NumberTheoryCalculator calc;
        int a = 15;
        int b = 0;

        // ACT

        // ASSERT
        BOOST_CHECK_THROW(calc.divisible(a,b), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(check_valid_mcd)
    {
        // ARRANGE
        NumberTheoryCalculator calc;
        int a = 745;
        int b = 547;

        // ACT
        int mcd = calc.mcd(a,b);

        // ASSERT
        BOOST_CHECK(calc.divisible(a,mcd) && calc.divisible(b,mcd)); // weak check
    }

    BOOST_AUTO_TEST_CASE(check_valid_mcm)
    {
        // ARRANGE
        NumberTheoryCalculator calc;
        int a = 745;
        int b = 547;
        // ACT
        int mcm = calc.mcm(a,b);

        // ASSERT
        BOOST_CHECK(calc.divisible(mcm,a) && calc.divisible(mcm,b)); // weak check
    }

    BOOST_AUTO_TEST_CASE(check_double_0_mcd)
    {
        // ARRANGE
        NumberTheoryCalculator calc;
        int cero = 0;

        // ACT & ASSERT
        BOOST_CHECK_THROW(calc.mcd(cero,cero), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(check_valid_first_0_mcd)
    {
        // ARRANGE
        NumberTheoryCalculator calc;
        int cero = 0;
        int a = 1;

        // ACT
        int mcd = calc.mcd(cero,a);

        // ASSERT
        BOOST_CHECK(mcd == a);
    }

    BOOST_AUTO_TEST_CASE(check_invalid_first_negative_mcd)
    {
        // ARRANGE
        NumberTheoryCalculator calc;
        int neg1 = -1;
        int pos1 = 1;

        // ACT & ASSERT
        BOOST_CHECK_THROW(calc.mcd(neg1,pos1), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(check_invalid_second_negative_mcd)
    {
        // ARRANGE
        NumberTheoryCalculator calc;
        int neg1 = -1;
        int pos1 = 1;

        // ACT & ASSERT
        BOOST_CHECK_THROW(calc.mcd(pos1,neg1), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(check_correct_new) // tuve que hacer esto para que lcov tome el header como completo
    {
        NumberTheoryCalculator* calc;
        BOOST_CHECK_NO_THROW(calc = new NumberTheoryCalculator);
        BOOST_CHECK_NO_THROW(delete calc);
    }

BOOST_AUTO_TEST_SUITE_END()