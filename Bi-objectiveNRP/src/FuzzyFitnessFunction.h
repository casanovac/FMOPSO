//
// Created by carlos on 22/11/18.
//

#ifndef BI_OBJECTIVENRP_FUZZYFITNESSFUNCTION_H
#define BI_OBJECTIVENRP_FUZZYFITNESSFUNCTION_H


#include <eoEvalFunc.h>
#include <fitness/moeoSingleObjectivization.h>
#include "AbstractFuzzyTNorm.h"

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
