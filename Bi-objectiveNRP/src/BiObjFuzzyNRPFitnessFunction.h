//
// Created by carlos on 26/11/18.
//

#ifndef BI_OBJECTIVENRP_BIOBJFUZZYNRPFITNESSFUNCTION_H
#define BI_OBJECTIVENRP_BIOBJFUZZYNRPFITNESSFUNCTION_H


#include "FuzzyFitnessFunction.h"
#include "BinaryParticle.h"
#include "CostNRPAttribute.h"
#include "ProfitNRPAttribute.h"
#include "LinearMonotonicFuzzyNumber.h"
#include "MinFuzzyTNorm.h"
#include "ExpWeightedFuzzyNumberDecorator.h"
#include "BiObjFuzzyNRPFitness.h"

class BiObjFuzzyNRPFitnessFunction : public FuzzyFitnessFunction<BinaryParticle<BiObjFuzzyNRPFitness> > {
public:
    BiObjFuzzyNRPFitnessFunction(const std::string &NRPInstanceFileName, double bestProfit, double worstCost,
                                     double expWProfit, double expWCost)
    {
        this->loadInstance(NRPInstanceFileName);
        m_cost_attr = new CostNRPAttribute(m_instance);
        m_profit_attr = new ProfitNRPAttribute(m_instance);
        m_cost_objective = new ExpWeightedFuzzyNumberDecorator<LinearMonotonicFuzzyNumber>(LinearMonotonicFuzzyNumber(0.0, worstCost, LinearMonotonicFuzzyNumber::DESCENDING), expWCost);
        m_profit_objective = new ExpWeightedFuzzyNumberDecorator<LinearMonotonicFuzzyNumber>(LinearMonotonicFuzzyNumber(0.0, bestProfit, LinearMonotonicFuzzyNumber::ASCENDING), expWProfit);
        m_tnorm = new MinFuzzyTNorm();
    }

    void operator()(BinaryParticle<BiObjFuzzyNRPFitness> &_bp)
    {
        BiObjFuzzyNRPFitness fitness;
        fitness.setCost((*m_cost_attr)(_bp));
        fitness.setProfit((*m_profit_attr)(_bp));
        fitness.setCostMembership((*m_cost_objective)(fitness.getCost()));
        fitness.setProfitMembership((*m_profit_objective)(fitness.getProfit()));
        fitness.setValue((*m_tnorm)(fitness.getCostMembership(), fitness.getProfitMembership()));

        _bp.fitness(fitness);
    }

    virtual ~BiObjFuzzyNRPFitnessFunction()
    {
        delete m_cost_attr;
        delete m_profit_attr;
        delete m_cost_objective;
        delete m_profit_objective;
        delete m_tnorm;
    }

protected:
    NRPProblem m_instance;
    CostNRPAttribute* m_cost_attr;
    FuzzyNumber* m_cost_objective;
    ProfitNRPAttribute* m_profit_attr;
    FuzzyNumber* m_profit_objective;

private:

    void loadInstance(const std::string& NRPInstanceFileName)
    {
        m_instance.load(NRPInstanceFileName);
    }
};


#endif //BI_OBJECTIVENRP_BIOBJFUZZYNRPFITNESSFUNCTION_H
