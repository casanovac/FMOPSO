//
// Created by carlos on 22/11/18.
//

#ifndef BI_OBJECTIVENRP_LRFUZZYNUMBER_H
#define BI_OBJECTIVENRP_LRFUZZYNUMBER_H


#include <functional>
#include "FuzzyNumber.h"

/**
 * LR Fuzzy Number implementation from Didier Dubois and Henri Prade.
 * Fuzzy Sets and Systems: Theory and Applications (1980)
 */
class LRFuzzyNumber : public FuzzyNumber{
public:
    /**
     * Full Constructor of LR Representation on fuzzy numbers
     * A function, usually denoted L or R, is a reference function of fuzzy numbers iff
     * (1) L(x) = L(-x);
     * (2) L(0) = 1;
     * (3) L is nonincreasing on [0, infinity).
     * @param supportsInf
     * @param supportsSup
     * @param m Mean value
     * @param alpha Left spread, real positive
     * @param beta Right spread, real positive
     * @param L Left reference
     * @param R Right Reference
     */
    LRFuzzyNumber(double m, double alpha, double beta, std::function<float(double)> L, std::function<float(double)> R, double supportsInf,
                  double supportsSup) : FuzzyNumber(supportsInf, supportsSup), m(m), alpha(alpha), beta(beta), L(L),
                                        R(R) {}

    LRFuzzyNumber(double m, double alpha, double beta, float (*L)(double), float (*R)(double)) : m(m), alpha(alpha),
                                                                                                 beta(beta), L(L),
                                                                                                 R(R) {}

    LRFuzzyNumber(const LRFuzzyNumber &anotherNumber) : FuzzyNumber(anotherNumber), m(anotherNumber.m),
                                                        alpha(anotherNumber.alpha), beta(anotherNumber.beta),
                                                        L(anotherNumber.L), R(anotherNumber.R){}

    /**
     * Returns membership value in this Fuzzy Set for domain element x
     * @param x Domain element, real value
     * @return membership value for domain element x
     */
    float operator()(double x) override
    {
        float result;
        if(x < supportsInf || x > supportsSup)
            result = 0;
        else
            result = (x <= m) ? (L((m-x)/alpha)) : (R((x-m)/beta));
        return result;
    }

protected:
    double m, alpha, beta;
    std::function<float(double)> L;
    std::function<float(double)> R;
};


#endif //BI_OBJECTIVENRP_LRFUZZYNUMBER_H
