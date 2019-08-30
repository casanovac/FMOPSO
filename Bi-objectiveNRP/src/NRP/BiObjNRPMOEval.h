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
// Created by carlos on 29/11/18.
//

#ifndef BI_OBJECTIVENRP_BIOBJNRPMOEVAL_H
#define BI_OBJECTIVENRP_BIOBJNRPMOEVAL_H


#include <core/moeoEvalFunc.h>
#include "BiObjNRPVectorTraits.h"
#include "NRP/NRPProblem.h"
#include "CostNRPAttribute.h"
#include "NRP/ProfitNRPAttribute.h"
#include "MOBinaryParticle.h"

template <class MOEO>
class BiObjNRPMOEval : public moeoEvalFunc<MOEO> {
public:
    BiObjNRPMOEval(const std::string &NRPInstanceFileName) {
        this->loadInstance(NRPInstanceFileName);
        m_cost_attr = new CostNRPAttribute(m_instance);
        m_profit_attr = new ProfitNRPAttribute(m_instance);
    }


    void operator()(MOEO &_bp){
        typename MOEO::ObjectiveVector vec;
        double profit = m_profit_attr->operator()(_bp);
        double cost = m_cost_attr->operator()(_bp);
        vec[0] = profit;
        vec[1] = cost;
        _bp.objectiveVector(vec);
    }

    virtual ~BiObjNRPMOEval() {
        delete m_cost_attr;
        delete m_profit_attr;
    }

protected:
    NRPProblem m_instance;
    CostNRPAttribute *m_cost_attr;
    ProfitNRPAttribute *m_profit_attr;

private:
    void loadInstance(const std::string &NRPInstanceFileName) {
        m_instance.load(NRPInstanceFileName);
    }
};


#endif //BI_OBJECTIVENRP_BIOBJNRPMOEVAL_H
