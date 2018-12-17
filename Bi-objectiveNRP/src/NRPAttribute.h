//
// Created by carlos on 16/11/18.
//

#ifndef BI_OBJECTIVENRP_NRPATTRIBUTE_H
#define BI_OBJECTIVENRP_NRPATTRIBUTE_H


#include <functional>
#include <eoFunctor.h>
#include "NRPProblem.h"

class NRPAttribute : public eoUF<const std::vector<bool>&, double>{
public:

    //virtual double calculate(const std::vector<bool>& _bp) = 0;

    double operator()(const std::vector<bool>& _bp) = 0;

protected:
    NRPAttribute(const NRPProblem &_instance) : m_instance(_instance) {}

public:
    NRPAttribute(const NRPAttribute& anotherAttribute) : m_instance(anotherAttribute.m_instance) {}

protected:
    NRPProblem m_instance;
};


#endif //BI_OBJECTIVENRP_NRPATTRIBUTE_H
