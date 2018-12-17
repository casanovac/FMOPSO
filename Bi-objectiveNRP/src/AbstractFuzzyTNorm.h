//
// Created by carlos on 26/11/18.
//

#ifndef BI_OBJECTIVENRP_ABSTRACTFUZZYTNORM_H
#define BI_OBJECTIVENRP_ABSTRACTFUZZYTNORM_H


#include <eoFunctor.h>

class AbstractFuzzyTNorm : public eoBF<float, float, float>{
public:
    float operator()(float membershipValue1, float membershipValue2) = 0;
};


#endif //BI_OBJECTIVENRP_ABSTRACTFUZZYTNORM_H
