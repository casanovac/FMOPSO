/*
 * NumberTheoryCalculator.h
 *
 *  Created on: 18 oct. 2018
 *      Author: carlos
 */

#ifndef NUMBERTHEORYCALCULATOR_H_
#define NUMBERTHEORYCALCULATOR_H_

class NumberTheoryCalculator {
public:
    NumberTheoryCalculator();
    int signo(int);
    int div(int, int);
    int mod(int, int);
    int mcd(int, int);
    int mcm(int, int);
    bool divisible(int, int);
    virtual ~NumberTheoryCalculator();
};

#endif /* NUMBERTHEORYCALCULATOR_H_ */
