//
// Created by carlos on 20/11/18.
//

#ifndef BI_OBJECTIVENRP_PROFITNRPATTRIBUTE_H
#define BI_OBJECTIVENRP_PROFITNRPATTRIBUTE_H


#include "NRPAttribute.h"

class ProfitNRPAttribute : public NRPAttribute {
public:
    ProfitNRPAttribute(const NRPProblem &_instance) : NRPAttribute(_instance) {}

    double operator()(const std::vector<bool> &_bp) override
    {
        double sum(0.0);
        std::vector<bool> satisfiedCustomers(m_instance.getCustomersProfit().size(), true);
        for(std::set<std::pair<unsigned int, unsigned int> >::iterator it = m_instance.getInterestRelation().begin(); it != m_instance.getInterestRelation().end(); it++)
        {
            std::pair<unsigned int, unsigned int> interestPair = *it;
            if(!_bp.at(interestPair.second))
                satisfiedCustomers.at(interestPair.first) = false;
        }

        for (unsigned int i = 0; i < this->m_instance.getCustomersProfit().size(); i++) {
            if (satisfiedCustomers.at(i))
                sum += this->m_instance.getCustomersProfit().at(i);
        }
        return sum;

    }
};


#endif //BI_OBJECTIVENRP_PROFITNRPATTRIBUTE_H
