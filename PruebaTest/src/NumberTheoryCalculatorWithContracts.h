/*
 * NumberTheoryCalculator.h
 *
 *  Created on: 18 oct. 2018
 *      Author: carlos
 */

#ifndef NUMBERTHEORYCALCULATORWITHCONTRACTS_H_
#define NUMBERTHEORYCALCULATORWITHCONTRACTS_H_

class NumberTheoryCalculatorWithContracts {
public:
    NumberTheoryCalculatorWithContracts();
    int signo(int);
    int div(int, int);
    int mod(int, int);
    int mcd(int, int);
    int mcm(int, int);
    bool divisible(int, int);
    virtual ~NumberTheoryCalculatorWithContracts();
};

#endif /* NUMBERTHEORYCALCULATORWITHCONTRACTS_H_ */
