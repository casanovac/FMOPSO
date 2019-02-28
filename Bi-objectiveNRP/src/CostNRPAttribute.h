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
