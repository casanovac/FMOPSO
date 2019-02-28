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
// Created by carlos on 27/11/18.
//

#ifndef BI_OBJECTIVENRP_BIOBJNRPVECTORTRAITS_H
#define BI_OBJECTIVENRP_BIOBJNRPVECTORTRAITS_H


#include <core/moeoObjectiveVectorTraits.h>
#include <core/moeoRealObjectiveVector.h>

class BiObjNRPVectorTraits : public moeoObjectiveVectorTraits{
public:
    static bool minimizing (int i)
    {
        return i == 1; // Cost
    }
    static bool maximizing (int i)
    {
        return i == 0; // Profit
    }
    static unsigned int nObjectives ()
    {
        return 2;
    }
};

typedef moeoRealObjectiveVector < BiObjNRPVectorTraits > BiObjNRPObjectiveVector;
#endif //BI_OBJECTIVENRP_BIOBJNRPVECTORTRAITS_H
