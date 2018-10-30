/*
 * NumberTheoryCalculator.cpp
 *
 *  Created on: 18 oct. 2018
 *      Author: carlos
 */

#include "NumberTheoryCalculator.h"
#include <stdexcept>

NumberTheoryCalculator::NumberTheoryCalculator() = default;

int NumberTheoryCalculator::signo(int entero)
{
    if(entero > 0) return 1;
    if(entero < 0) return -1;
    return 0;
}

int NumberTheoryCalculator::div(int dividendo, int divisor)
{
    if(divisor <= 0)
        throw std::invalid_argument("Divisor debe ser positivo");

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

int NumberTheoryCalculator::mod(int dividendo, int divisor)
{
    return dividendo - divisor * div(dividendo, divisor);
}

bool NumberTheoryCalculator::divisible(int dividendo, int divisor)
{
    return mod(dividendo, divisor) == 0;
}

int NumberTheoryCalculator::mcd(int a, int b)
{
    if(a < 0 || b < 0 || (a == 0 && b == 0))
        throw std::invalid_argument("a y b (argumentos de mcd) deben ser no negativos, no ambos 0");

    while(b != 0)
    {
        int r = mod(a, b);
        a = b;
        b = r;
    }
    return a;
}

int NumberTheoryCalculator::mcm(int a, int b)
{
    return a * b / mcd(a,b);
}

NumberTheoryCalculator::~NumberTheoryCalculator() = default;
