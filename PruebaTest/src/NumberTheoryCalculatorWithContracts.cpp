/*
 * NumberTheoryCalculatorWithContracts.cpp
 *
 *  Created on: 18 oct. 2018
 *      Author: carlos
 */

#include "NumberTheoryCalculatorWithContracts.h"
#include <boost/contract.hpp>

NumberTheoryCalculatorWithContracts::NumberTheoryCalculatorWithContracts() noexcept = default;

int NumberTheoryCalculatorWithContracts::signo(int entero)
{
    if(entero > 0) return 1;
    if(entero < 0) return -1;
    return 0;
}

int NumberTheoryCalculatorWithContracts::div(int dividendo, int divisor)
{
    int cociente = 0;
    int resto = dividendo;
    boost::contract::old_ptr<int> old_dividendo = BOOST_CONTRACT_OLDOF(dividendo); // Old value.
    boost::contract::old_ptr<int> old_divisor = BOOST_CONTRACT_OLDOF(divisor); // Old value.
    boost::contract::check c = boost::contract::function()  // Same for all other contracts.
            .precondition([&] {                             // Capture by reference or value...
                BOOST_CONTRACT_ASSERT(divisor > 0);         // ...and should not modify captures.
            })
            .postcondition([&] {
                BOOST_CONTRACT_ASSERT(*old_dividendo == *old_divisor * cociente + resto && resto >= 0 && resto < *old_divisor);
            })
            ;


    int signo_div = signo(dividendo);
    while(resto < 0 || resto >= divisor)
    {
        resto = resto - signo_div * divisor;
        cociente = cociente + signo_div;
    }
    return cociente;
}

int NumberTheoryCalculatorWithContracts::mod(int dividendo, int divisor)
{
    int resto;
    boost::contract::old_ptr<int> old_dividendo = BOOST_CONTRACT_OLDOF(dividendo); // Old value.
    boost::contract::old_ptr<int> old_divisor = BOOST_CONTRACT_OLDOF(divisor); // Old value.
    boost::contract::check c = boost::contract::function()  // Same for all other contracts.
            .precondition([&] {                             // Capture by reference...
                BOOST_CONTRACT_ASSERT(divisor > 0);         // ...and should not modify captures.
            })
            .postcondition([&] {
                BOOST_CONTRACT_ASSERT(divisible(*old_dividendo - resto, *old_divisor));
            })
    ;
    return resto = dividendo - divisor * div(dividendo, divisor);
}

bool NumberTheoryCalculatorWithContracts::divisible(int dividendo, int divisor)
{
    boost::contract::check c = boost::contract::function()  // Same for all other contracts.
            .precondition([&] {                             // Capture by reference or value...
                BOOST_CONTRACT_ASSERT(divisor > 0);         // ...and should not modify captures.
            })
    ;
    return mod(dividendo, divisor) == 0;
}

int NumberTheoryCalculatorWithContracts::mcd(int a, int b)
{
    boost::contract::old_ptr<int> old_a = BOOST_CONTRACT_OLDOF(a); // Old value.
    boost::contract::old_ptr<int> old_b = BOOST_CONTRACT_OLDOF(b); // Old value.
    boost::contract::check c = boost::contract::function()                          // Same for all other contracts.
            .precondition([&] {                                                     // Capture by reference or value...
                BOOST_CONTRACT_ASSERT(a >= 0 && b >= 0 && !(a == 0 && b == 0));     // ...and should not modify captures.
            })
            .postcondition([&] {
                BOOST_CONTRACT_ASSERT(divisible(*old_a , a ) && divisible(*old_b , a ));
            })
            ;

    while(b != 0)
    {
        int r = mod(a, b);
        a = b;
        b = r;
    }
    return a;
}

int NumberTheoryCalculatorWithContracts::mcm(int a, int b)
{
    int result;
    boost::contract::check c = boost::contract::function()                          // Same for all other contracts.
            .precondition([&] {                                                     // Capture by reference or value...
                BOOST_CONTRACT_ASSERT(a > 0 && b > 0);     // ...and should not modify captures.
            })
            .postcondition([&] {
                BOOST_CONTRACT_ASSERT(divisible(result , a ) && divisible(result , a ));
            })
            ;
    return result = a * b / mcd(a,b);
}

NumberTheoryCalculatorWithContracts::~NumberTheoryCalculatorWithContracts() = default;
