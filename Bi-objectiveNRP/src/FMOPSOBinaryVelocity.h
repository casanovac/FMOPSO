//
// Created by carlos on 26/11/18.
//

#ifndef BI_OBJECTIVENRP_FMOPSOBINARYVELOCITY_H
#define BI_OBJECTIVENRP_FMOPSOBINARYVELOCITY_H


#include "BinaryVelocity.h"
#include "FMOPSOTopology.h"

template <class POT>
class FMOPSOBinaryVelocity : public BinaryVelocity<POT>{
public:
    FMOPSOBinaryVelocity(eoTopology<POT> &_topology, eoRng &_gen) : BinaryVelocity<POT>::BinaryVelocity(_topology, _gen) {}

    void operator()(POT &_po, unsigned _indice) override
    {
        FMOPSOTopology<POT>* topology = (FMOPSOTopology<POT>*)&this->topology;

        unsigned columna = _indice % topology->getColumnas();
        typename POT::Fitness bestFitness = this->topology.best(columna).best();
        unsigned bestColumna = columna;
        if(columna > 0)
        {
            if(this->topology.best(columna - 1).best() > bestFitness)
            {
                bestFitness = this->topology.best(columna - 1).best();
                bestColumna = columna - 1;
            }
        }
        if(columna < topology->getColumnas() - 1)
        {
            if(this->topology.best(columna + 1).best() > bestFitness)
            {
                //bestFitness = this->topology.best(columna + 1);
                bestFitness = this->topology.best(columna + 1).best();
                bestColumna = columna + 1;
            }
        }
        // A VER SI CAMBIA ALGO
        /*unsigned bestColumna;
        if(columna == 0)
        {
            bestColumna = columna + 1;
        }
        else if(columna == topology->getColumnas() - 1)
        {
            bestColumna = columna - 1;
        }
        else
        {
            if(this->topology.best(columna - 1).best() > this->topology.best(columna + 1).best())
            {
                bestColumna = columna - 1;
            }
            else
            {
                bestColumna = columna - 1;
            }
        }
         */
        // FIN A VER SI CAMBIA ALGO
        //BinaryParticle<POT> bestNeighbor = this->topology.best(bestColumna);
        // assign the new velocities
        bool r1;
        bool r2;

        bool newVelocity;
        bool anyTrue = false;
        for (unsigned j = 0; j < _po.size (); j++)
        {
            r1 = BinaryVelocity<POT>::bool_gen();
            r2 = BinaryVelocity<POT>::bool_gen();
            newVelocity = ((r1 and (this->topology.best(columna)[j] xor _po[j])) or  (r2 and (this->topology.best(bestColumna)[j] xor _po[j])));
            _po.velocities[j] = newVelocity;
            anyTrue |= newVelocity;
        }
        if(anyTrue)
        {
            //std::cout << "Entré a mutar" << std::endl;
            _po.velocities[rng.random(_po.size())] = true;
        }
    }
};


#endif //BI_OBJECTIVENRP_FMOPSOBINARYVELOCITY_H
