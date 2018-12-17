//
// Created by carlos on 16/11/18.
//

#ifndef BI_OBJECTIVENRP_BINARYVELOCITY_H
#define BI_OBJECTIVENRP_BINARYVELOCITY_H


#include <eoVelocity.h>
#include <type_traits>
#include "BinaryParticle.h"

template <class POT>
class BinaryVelocity : public eoVelocity< POT > {
public:

    /** Full constructor: Bounds and bound modifier required
    * @param _topology - The topology to get the global/local/other best
    * @param _gen - The eo random generator, default=rng
    */
    BinaryVelocity (eoTopology <POT> & _topology,
    eoRng & _gen = rng):
    topology(_topology),
    bool_gen(0.5, _gen)
    {
        if(!std::is_same<typename POT::ParticleVelocityType, bool>::value)
            throw std::invalid_argument("");
    }

    void operator  () (POT & _po, unsigned _indice)
    {

        bool r1;
        bool r2;

        bool newVelocity;
        bool anyTrue = false;
        // assign the new velocities
        for (unsigned j = 0; j < _po.size (); j++)
        {
            r1 = bool_gen();
            r2 = bool_gen();
            //newVelocity = ((r1 and (_po.bestPositions[j] xor _po[j])) or  (r2 and (topology.best(_indice)[j] xor _po[j])));
            newVelocity = ((r1 and (_po.bestPositions[j] xor _po[j])) or  (r2 and (topology.best(_indice)[j] xor _po[j])));
            _po.velocities[j] = newVelocity;
            anyTrue |= newVelocity;
        }
        if(anyTrue)
        {
            _po.velocities[rng.random(_po.size())] = true;
        }
    }

    virtual void updateNeighborhood(POT & _po, unsigned _indice)
    {
        topology.updateNeighborhood(_po, _indice);
    }

    eoTopology<POT> &getTopology() override {
        return topology;
    }

protected:
    eoTopology <POT> & topology;
    eoBooleanGenerator bool_gen;
};


#endif //BI_OBJECTIVENRP_BINARYVELOCITY_H
