/*
 * NumberTheoryCalculatorWithContracts.cpp
 *
 *  Created on: 18 oct. 2018
 *      Author: carlos
 */

#include "NumberTheoryCalculatorWithContracts.h"
#include <boost/contract.hpp>

NumberTheoryCalculatorWithContracts::NumberTheoryCalculatorWithContracts() = default;

int NumberTheoryCalculatorWithContracts::signo(int entero)
{
    if(entero > 0) return 1;
    if(entero < 0) return -1;
    return 0;
}

int NumberTheoryCalculatorWithContracts::div(int dividendo, int divisor)
{
    boost::contract::check c = boost::contract::function()  // Same for all other contracts.
            .precondition([&] {                             // Capture by reference or value...
                BOOST_CONTRACT_ASSERT(divisor > 0);         // ...and should not modify captures.
            });

    int cociente = 0;
    int resto = dividendo;
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
    return dividendo - divisor * div(dividendo, divisor);
}

bool NumberTheoryCalculatorWithContracts::divisible(int dividendo, int divisor)
{
    return mod(dividendo, divisor) == 0;
}

int NumberTheoryCalculatorWithContracts::mcd(int a, int b)
{
    boost::contract::check c = boost::contract::function()                          // Same for all other contracts.
            .precondition([&] {                                                     // Capture by reference or value...
                BOOST_CONTRACT_ASSERT(a >= 0 && b >= 0 && !(a == 0 && b == 0));     // ...and should not modify captures.
            });

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
    return a * b / mcd(a,b);
}

NumberTheoryCalculatorWithContracts::~NumberTheoryCalculatorWithContracts() = default;
