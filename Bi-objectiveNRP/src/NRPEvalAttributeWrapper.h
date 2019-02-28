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
