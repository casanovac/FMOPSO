//
// Created by carlos on 16/11/18.
//

#ifndef BI_OBJECTIVENRP_NRPPARTICLE_H
#define BI_OBJECTIVENRP_NRPPARTICLE_H

#include <eo>
#include <eoVectorParticle.h>

template <class FitT>
class BinaryParticle : public eoVectorParticle<FitT, bool, bool>
{
    public:
        typedef bool ParticleVelocityType;

        //typedef typename eoVectorParticle<Scalar, bool, bool>::Fitness Fitness;
        BinaryParticle(unsigned size = 0, bool positions = 0, bool velocities = 0, bool bestPositions = 0): eoVectorParticle<FitT, bool, bool> (size, positions, velocities, bestPositions) {}
        BinaryParticle(const BinaryParticle<FitT>& anotherParticle) : eoVectorParticle<FitT, bool, bool> (anotherParticle.size(), 0, 0, 0)
        {
            this->fitness(anotherParticle.fitness());
            this->best(anotherParticle.best());
            this->assign(anotherParticle.cbegin(), anotherParticle.cend());
            this->bestPositions.assign(anotherParticle.bestPositions.cbegin(), anotherParticle.bestPositions.cend());
            this->velocities.assign(anotherParticle.velocities.cbegin(), anotherParticle.velocities.cend());
        }

        virtual std::string className() const
        {
            return "BinaryParticle";
        }
};


#endif //BI_OBJECTIVENRP_NRPPARTICLE_H
