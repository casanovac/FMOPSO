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
