// Copyright Carlos Antonio Casanova Pietroboni 2019
/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
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
