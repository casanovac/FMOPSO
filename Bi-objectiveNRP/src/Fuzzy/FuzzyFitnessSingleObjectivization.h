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
// Created by carlos on 30/11/18.
//

#ifndef BI_OBJECTIVENRP_FUZZYFITNESSSINGLEOBJECTIVIZATION_H
#define BI_OBJECTIVENRP_FUZZYFITNESSSINGLEOBJECTIVIZATION_H


#include <fitness/moeoSingleObjectivization.h>
#include <sstream>
#include <core/moeoEvalFunc.h>
#include "ExpWeightedFuzzyNumberDecorator.h"
#include "Fuzzy/AbstractFuzzyTNorm.h"
#include "MinFuzzyTNorm.h"

template<class MOEOT>
class FuzzyFitnessSingleObjectivization : public moeoSingleObjectivization<MOEOT>
{
public:
    typedef typename MOEOT::ObjectiveVector ObjectiveVector;

    FuzzyFitnessSingleObjectivization(moeoEvalFunc<MOEOT>* moEvalF, const std::vector<double> &leftReferences,
                                      const std::vector<double> &rightReferences, const std::vector<double> &expWeights)
    {
        if (!(ObjectiveVector::nObjectives() == leftReferences.size() &&
              ObjectiveVector::nObjectives() == rightReferences.size() &&
              ObjectiveVector::nObjectives() == expWeights.size()))
        {
            std::stringstream ss;
            ss << " Incorrect vector size while constructing FuzzyFitnessSingleObjectivization. ";
            ss << "Template determines " << ObjectiveVector::nObjectives() << " objectives. ";
            throw std::invalid_argument(ss.str());
        }
        if(moEvalF == nullptr)
            throw std::invalid_argument("Received nullptr as moEvalF in FuzzyFitnessSingleObjectivization ctor");
        this->eval = moEvalF;
        for (unsigned int i = 0; i < ObjectiveVector::nObjectives(); i++)
        {
            fuzzyCriterions.push_back(ExpWeightedLinearMonotonicFuzzyNumber(
                    LinearMonotonicFuzzyNumber(leftReferences.at(i), rightReferences.at(i),
                                               ObjectiveVector::minimizing(i) ? LinearMonotonicFuzzyNumber::DESCENDING
                                                                              : LinearMonotonicFuzzyNumber::ASCENDING), expWeights.at(i)));
        }
        tnorm = new MinFuzzyTNorm();
    }

    void operator()(MOEOT &_moeot) override
    {
        (*eval)(_moeot);
        _moeot.fitness(this->operator()(_moeot.objectiveVector()));
    }

    void updateByDeleting(eoPop<MOEOT> &_pop, ObjectiveVector &_objVec) override
    {

    }

    void operator()(eoPop<MOEOT> &_pop) override
    {
        for(MOEOT individual: _pop)
        {
            this->operator()(individual);
        }
    }

    typename MOEOT::Fitness operator()(const ObjectiveVector &_obj) override
    {
        typename MOEOT::Fitness fit(1.0);
        for(unsigned int i = 0; i < fuzzyCriterions.size(); i++)
        {
            fit = (*tnorm)(fit, fuzzyCriterions.at(i)(_obj.at(i)));
        }
        return fit;
    }

    virtual ~FuzzyFitnessSingleObjectivization()
    {
        delete tnorm;
    }

protected:
    std::vector<ExpWeightedLinearMonotonicFuzzyNumber> fuzzyCriterions;
    AbstractFuzzyTNorm *tnorm;
    moeoEvalFunc<MOEOT>* eval;
};


#endif //BI_OBJECTIVENRP_FUZZYFITNESSSINGLEOBJECTIVIZATION_H
