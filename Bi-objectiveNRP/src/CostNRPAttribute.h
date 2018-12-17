//
// Created by carlos on 16/11/18.
//

#ifndef BI_OBJECTIVENRP_COSTNRPATTRIBUTE_H
#define BI_OBJECTIVENRP_COSTNRPATTRIBUTE_H

#include "NRPAttribute.h"

class CostNRPAttribute : public NRPAttribute {
public:
    CostNRPAttribute(const NRPProblem &_instance) : NRPAttribute(_instance) {}

    double operator()(const std::vector<bool>& _bp)
    {
        double sum(0.0);
        std::_Bit_const_iterator it = _bp.cbegin();
        for(unsigned int i = 0; i < this->m_instance.getRequirementsCost().size(); i++)
        {
            if(*it)
                sum += this->m_instance.getRequirementsCost().at(i);
            it++;
        }
        return sum;
    }
private:

};

#endif //BI_OBJECTIVENRP_COSTNRPATTRIBUTE_H
