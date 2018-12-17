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
