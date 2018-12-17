//
// Created by carlos on 16/11/18.
//

#ifndef BI_OBJECTIVENRP_NRPEVALATTRIBUTEWRAPPER_H
#define BI_OBJECTIVENRP_NRPEVALATTRIBUTEWRAPPER_H


#include <eoEvalFunc.h>
#include "NRPAttribute.h"

template <class POT>
class NRPEvalAttributeWrapper : public eoEvalFunc< POT >
{
public:
    typedef typename POT::Fitness Fitness;
    NRPEvalAttributeWrapper(NRPAttribute* _attr)
    {
        this->attr = _attr;
    }

    void operator () (POT &_bp) override
    {
        Fitness fit = attr->operator()(_bp);
        _bp.fitness(fit);
    }

private:
    NRPAttribute* attr;

};


#endif //BI_OBJECTIVENRP_NRPEVALATTRIBUTEWRAPPER_H
