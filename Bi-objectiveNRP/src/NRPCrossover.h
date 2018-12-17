//
// Created by carlos on 04/12/18.
//

#ifndef BI_OBJECTIVENRP_NRPCROSSOVER_H
#define BI_OBJECTIVENRP_NRPCROSSOVER_H


#include <eoOp.h>

template <class MOEOT>
class NRPCrossover : public eoQuadOp<MOEOT>
{
public:
    bool operator()(MOEOT &a1, MOEOT &a2) override
    {
        /*
        // Collect all same-value indexes
        std::vector<unsigned int> sameValuePositions;
        for(unsigned int i = 0; i < a1.size(); i++)
        {
            if(a1[i] == a2[i])
                sameValuePositions.push_back(i);
        }
        // If any, select randomly, and cross
        if(sameValuePositions.size() > 0)
        {
            unsigned int pos = rng.random(sameValuePositions.size());
            MOEOT offspring1;
            offspring1.insert(offspring1.end(),a1.begin(),a1.begin()+sameValuePositions[pos]);
            offspring1.insert(offspring1.end(),a2.begin()+sameValuePositions[pos],a2.end());
            MOEOT offspring2;
            offspring2.insert(offspring2.end(),a2.begin(),a2.begin()+sameValuePositions[pos]);
            offspring2.insert(offspring2.end(),a1.begin()+sameValuePositions[pos],a1.end());
            if(a1 != offspring1 || a2 != offspring2)
            {
                a1 = offspring1;
                a2 = offspring2;
                return true;
            }
            return false;
        }

        // Else, return false
        else
            return false;
        */
        MOEOT offspring1(a1.size());
        MOEOT offspring2(a2.size());
        for(unsigned int i = 0; i < a1.size(); i++)
        {
            offspring1[i] = a1[i] or a2[i];
            offspring2[i] = a1[i] and a2[i];
        }
        if(a1 != offspring1 || a2 != offspring2)
        {
            a1 = offspring1;
            a2 = offspring2;
            return true;
        }
        else
            return false;
    }
};


#endif //BI_OBJECTIVENRP_NRPCROSSOVER_H
