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
// Created by carlos on 22/11/18.
//

#ifndef BI_OBJECTIVENRP_FUZZYFITNESSFUNCTION_H
#define BI_OBJECTIVENRP_FUZZYFITNESSFUNCTION_H


#include <eoEvalFunc.h>
#include <fitness/moeoSingleObjectivization.h>
#include "Fuzzy/AbstractFuzzyTNorm.h"

template <class POT>
class FuzzyFitnessFunction : public /*moeoSingleObjectivization<POT>*/eoEvalFunc<POT> {
public:
    AbstractFuzzyTNorm *getTnorm() const {
        return m_tnorm;
    }

    void setTnorm(AbstractFuzzyTNorm *m_tnorm) {
        if(m_tnorm == nullptr)
            throw std::invalid_argument("En setTnorm, debe proporcionar un puntero a una tnorma válida");
        this->m_tnorm = m_tnorm;
    }

    virtual void operator()(POT &a1) = 0;

    /*virtual void operator()(eoPop<POT> &a1) = 0;

    virtual typename POT::Fitness operator()(const typename POT::ObjectiveVector &_obj) = 0;

    void updateByDeleting(eoPop<POT> &_pop, typename POT::ObjectiveVector &_objVec) override {

    }*/


protected:
    AbstractFuzzyTNorm* m_tnorm;
};


#endif //BI_OBJECTIVENRP_FUZZYFITNESSFUNCTION_H
