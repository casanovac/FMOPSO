//
// Created by carlos on 26/11/18.
//

#ifndef BI_OBJECTIVENRP_MINFUZZYTNORM_H
#define BI_OBJECTIVENRP_MINFUZZYTNORM_H


#include "AbstractFuzzyTNorm.h"

class MinFuzzyTNorm : public AbstractFuzzyTNorm{
public:
    float operator()(float membershipValue1, float membershipValue2) override
    {
        return std::min(membershipValue1, membershipValue2);
    }
};


#endif //BI_OBJECTIVENRP_MINFUZZYTNORM_H
