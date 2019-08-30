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
// Created by carlos on 26/11/18.
//

#ifndef BI_OBJECTIVENRP_MINFUZZYTNORM_H
#define BI_OBJECTIVENRP_MINFUZZYTNORM_H


#include "Fuzzy/AbstractFuzzyTNorm.h"

class MinFuzzyTNorm : public AbstractFuzzyTNorm{
public:
    float operator()(float membershipValue1, float membershipValue2) override
    {
        return std::min(membershipValue1, membershipValue2);
    }
};


#endif //BI_OBJECTIVENRP_MINFUZZYTNORM_H
