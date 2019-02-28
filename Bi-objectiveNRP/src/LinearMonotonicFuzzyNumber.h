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

#ifndef BI_OBJECTIVENRP_LINEARMONOTONICFUZZYNUMBER_H
#define BI_OBJECTIVENRP_LINEARMONOTONICFUZZYNUMBER_H


#include <stdexcept>
#include "LRFuzzyNumber.h"

class LinearMonotonicFuzzyNumber : public LRFuzzyNumber{
public:
    static const short ASCENDING = 1;
    static const short DESCENDING = -1;

    LinearMonotonicFuzzyNumber(double leftReference, double rightReference, short asc_desc) : LRFuzzyNumber(0,1,1,0,0), asc_desc(asc_desc)
    {
        if(asc_desc == ASCENDING)
        {
            this->m = rightReference;
            this->alpha = rightReference - leftReference;
            this->beta = 1;
            this->L = [=](double x){ return 1.0 - x;};
            this->R = [=](double x){ return 1;};
            this->supportsInf = leftReference;
            this->supportsSup = std::numeric_limits<double>::max();
        }
        else if(asc_desc == DESCENDING)
        {
            this->m = leftReference;
            this->alpha = 1;
            this->beta = rightReference - leftReference;
            this->L = [=](double x){ return 1.0;};
            this->R = [=](double x){ return 1.0 - x;};
            this->supportsInf = std::numeric_limits<double>::lowest();
            this->supportsSup = rightReference;
        }
        else
            throw std::invalid_argument("In LinearMonotonicFuzzyNumber received invalid argument. asc_desc param must be either LinearMonotonicFuzzyNumber::ASCENDING or LinearMonotonicFuzzyNumber::DESCENDING.");

    }

    LinearMonotonicFuzzyNumber(const LinearMonotonicFuzzyNumber &anotherNumber) : LRFuzzyNumber(anotherNumber), asc_desc(anotherNumber.asc_desc) {}

private:
    short asc_desc;
};


#endif //BI_OBJECTIVENRP_LINEARMONOTONICFUZZYNUMBER_H
