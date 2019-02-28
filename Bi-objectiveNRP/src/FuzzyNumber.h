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
// Created by carlos on 22/11/18.
//

#ifndef BI_OBJECTIVENRP_FUZZYNUMBER_H
#define BI_OBJECTIVENRP_FUZZYNUMBER_H


#include <limits>
#include <eoFunctor.h>

class FuzzyNumber : public eoUF<double, float>{
public:
    /**
     * Default constructor
     * @param supportsInf The leftmost number in FuzzyNumber's support. Default = std::numeric_limits<double>::lowest()
     * @param supportsSup The rightmost number in FuzzyNumber's support. Default = std::numeric_limits<double>::max()
     */
    FuzzyNumber(double supportsInf = std::numeric_limits<double>::lowest(), double supportsSup = std::numeric_limits<double>::max()) : supportsInf(supportsInf), supportsSup(supportsSup) {}

    FuzzyNumber(const FuzzyNumber& anotherNumber) : supportsInf(anotherNumber.supportsInf), supportsSup(anotherNumber.supportsSup) {}

    /**
     * Abstract function that must be implemented by all FuzzyNumber concrete subclasses
     * @param x the domain element whose membership value is looked for
     * @return the membership value for element x
     */
    float operator()(double x) = 0;

protected:
    double supportsInf, supportsSup;
};


#endif //BI_OBJECTIVENRP_FUZZYNUMBER_H
