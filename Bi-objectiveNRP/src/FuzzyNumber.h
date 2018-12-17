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
