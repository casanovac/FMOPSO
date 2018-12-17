//
// Created by carlos on 29/11/18.
//

#ifndef BI_OBJECTIVENRP_MOBINARYPARTICLE_H
#define BI_OBJECTIVENRP_MOBINARYPARTICLE_H


#include "MOVectorParticle.h"
template <class MOEOObjectiveVector, class MOEOFitness = double, class MOEODiversity = double>
class MOBinaryParticle : public MOVectorParticle<MOEOObjectiveVector, bool, bool, MOEOFitness, MOEODiversity>
{
public:
    MOBinaryParticle(unsigned int _size = 0, bool _position = false, bool _velocity = false, bool _bestPositions = false) : MOVectorParticle<MOEOObjectiveVector, bool, bool, MOEOFitness, MOEODiversity>(_size,
                                                                                                                 _position,
                                                                                                                 _velocity,
                                                                                                                 _bestPositions)
    {}

    MOBinaryParticle(const MOBinaryParticle<MOEOObjectiveVector, MOEOFitness, MOEODiversity>& anotherParticle) : MOVectorParticle<MOEOObjectiveVector, bool, bool, MOEOFitness, MOEODiversity> (anotherParticle){}

    virtual std::string className() const
    {
        return "MOBinaryParticle";
    }
};


#endif //BI_OBJECTIVENRP_MOBINARYPARTICLE_H
