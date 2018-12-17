//
// Created by carlos on 23/11/18.
//

#ifndef BI_OBJECTIVENRP_EXPWEIGHTEDFUZZYNUMBERDECORATOR_H
#define BI_OBJECTIVENRP_EXPWEIGHTEDFUZZYNUMBERDECORATOR_H


#include <cmath>
#include "FuzzyNumber.h"
#include "LinearMonotonicFuzzyNumber.h"

template <class FN>
class ExpWeightedFuzzyNumberDecorator : public FuzzyNumber{
public:
    ExpWeightedFuzzyNumberDecorator(FN decoratedFN, double expWeight) : decoratedFN(decoratedFN),
                                                                        expWeight(expWeight) {}

    float operator()(double x)
    {
        float result = decoratedFN(x);
        if(result != 0)
            result = std::pow(result, expWeight);
        return result;
    }
private:
    FN decoratedFN;
    double expWeight;
};

typedef ExpWeightedFuzzyNumberDecorator<LinearMonotonicFuzzyNumber> ExpWeightedLinearMonotonicFuzzyNumber;

#endif //BI_OBJECTIVENRP_EXPWEIGHTEDFUZZYNUMBERDECORATOR_H
