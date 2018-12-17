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
