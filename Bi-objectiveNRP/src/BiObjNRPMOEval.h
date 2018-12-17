//
// Created by carlos on 29/11/18.
//

#ifndef BI_OBJECTIVENRP_BIOBJNRPMOEVAL_H
#define BI_OBJECTIVENRP_BIOBJNRPMOEVAL_H


#include <core/moeoEvalFunc.h>
#include "BiObjNRPVectorTraits.h"
#include "NRPProblem.h"
#include "CostNRPAttribute.h"
#include "ProfitNRPAttribute.h"
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
