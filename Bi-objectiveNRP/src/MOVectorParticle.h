//
// Created by carlos on 29/11/18.
//

#ifndef BI_OBJECTIVENRP_MOVECTORPARTICLE_H
#define BI_OBJECTIVENRP_MOVECTORPARTICLE_H

#include <core/MOEO.h>
#include <eoVectorParticle.h>
#include <ostream>

template <class MOEOObjectiveVector, class PositionType, class VelocityType, class MOEOFitness=double, class MOEODiversity=double>
class MOVectorParticle : public MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>, public eoVectorParticle<MOEOFitness, PositionType, VelocityType>
{
public:
    typedef typename MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>::Fitness Fitness;
    using eoVectorParticle<MOEOFitness, PositionType, VelocityType>::operator[];
    using eoVectorParticle<MOEOFitness, PositionType, VelocityType>::size;
    using eoVectorParticle<MOEOFitness, PositionType, VelocityType>::begin;
    using eoVectorParticle<MOEOFitness, PositionType, VelocityType>::end;
    using MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>::ObjectiveVector;


    /**
     * Default constructor
     * @param _size
     * @param _position
     * @param _velocity
     * @param _bestPositions
     */
    MOVectorParticle(unsigned int _size = 0, PositionType _position = PositionType (), VelocityType _velocity = VelocityType (), PositionType _bestPositions = PositionType ()) : MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>(), eoVectorParticle<MOEOFitness, PositionType, VelocityType>(_size, _position, _velocity, _bestPositions)
    {
        bestObjectiveVectorValue = MOEOObjectiveVector();
        invalidBestObjectiveVectorValue = true;
    }

    /**
     * Copy Ctor
     * @param another
     */
    MOVectorParticle(const MOVectorParticle& another) : MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>::MOEO(), eoVectorParticle<MOEOFitness, PositionType, VelocityType>::eoVectorParticle(another.size(), 0, 0, 0)
    {
        this->fitness(another.fitness());
        this->best(another.best());
        this->assign(another.cbegin(), another.cend());
        this->bestPositions.assign(another.bestPositions.cbegin(), another.bestPositions.cend());
        this->velocities.assign(another.velocities.cbegin(), another.velocities.cend());
        this->objectiveVector(another.objectiveVector());
        this->bestObjectiveVectorValue = another.bestObjectiveVectorValue;
        this->invalidBestObjectiveVectorValue = another.invalidBestObjectiveVectorValue;
        this->objectiveVector(another.objectiveVector());
        //this->diversity(another.diversity());
    }

    void readFrom(std::istream &_is)
    {
        MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>::readFrom(_is);
        eoVectorParticle<MOEOFitness, PositionType, VelocityType>::readFrom(_is);
    }

    /*unsigned long size() const
    {
        return eoVectorParticle<MOEOFitness, PositionType, VelocityType>::size();
    }*/

    void fitness(const Fitness &_fitness)
    {
        MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>::fitness(_fitness);
        eoVectorParticle<MOEOFitness, PositionType, VelocityType>::fitness(_fitness);
    }

    const Fitness fitness() const
    {
        return MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>::fitness();
    }

    /**
     *
     * @param os
     */
    virtual void printOn(std::ostream &os) const
    {
        MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>::printOn(os);
        eoVectorParticle<MOEOFitness, PositionType, VelocityType>::printOn(os);
    }

    friend std::ostream &operator<<(std::ostream &os, const MOVectorParticle &particle)
    {
        particle.printOn(os);
        return os;
    }

    /**
     * Desambigüación del método invalidate
     */
    void invalidate()
    {
        MOEO<MOEOObjectiveVector, MOEOFitness, MOEODiversity>::invalidate();
        eoVectorParticle<MOEOFitness, PositionType, VelocityType>::invalidate();
        invalidateBestObjectiveVector();
    }

    void invalidateBestObjectiveVector()
    {
        this->invalidBestObjectiveVectorValue = true;
    }

    MOEOObjectiveVector getBestObjectiveVectorValue() const {
        return bestObjectiveVectorValue;
    }

    void setBestObjectiveVectorValue(MOEOObjectiveVector bestObjectiveVectorValue) {
        MOVectorParticle::bestObjectiveVectorValue = bestObjectiveVectorValue;
        invalidBestObjectiveVectorValue = false;
    }

    /// to avoid conflicts between PSO and MOEO
    bool operator<(const MOVectorParticle<MOEOObjectiveVector, PositionType, VelocityType, MOEOFitness, MOEODiversity>& _vp) const
    {
        return eoVectorParticle<MOEOFitness, PositionType, VelocityType>::operator<(_vp);
    }

protected:
    MOEOObjectiveVector bestObjectiveVectorValue;
    /** true if the objective vector is invalid */
    bool invalidBestObjectiveVectorValue;
};


#endif //BI_OBJECTIVENRP_MOVECTORPARTICLE_H
