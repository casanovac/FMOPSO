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

#ifndef BI_OBJECTIVENRP_NRPATTRIBUTE_H
#define BI_OBJECTIVENRP_NRPATTRIBUTE_H


#include <functional>
#include <eoFunctor.h>
#include "NRPProblem.h"

class NRPAttribute : public eoUF<const std::vector<bool>&, double>{
public:

    //virtual double calculate(const std::vector<bool>& _bp) = 0;

    double operator()(const std::vector<bool>& _bp) = 0;

protected:
    NRPAttribute(const NRPProblem &_instance) : m_instance(_instance) {}

public:
    NRPAttribute(const NRPAttribute& anotherAttribute) : m_instance(anotherAttribute.m_instance) {}

protected:
    NRPProblem m_instance;
};


#endif //BI_OBJECTIVENRP_NRPATTRIBUTE_H
