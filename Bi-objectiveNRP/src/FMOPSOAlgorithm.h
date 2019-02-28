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
// Created by carlos on 26/11/18.
//

#ifndef BI_OBJECTIVENRP_FMOPSOALGORITHM_H
#define BI_OBJECTIVENRP_FMOPSOALGORITHM_H

#include <eoPSO.h>
#include <eoContinue.h>
#include <eoEvalFunc.h>
#include <eoVelocity.h>
#include <eoFlight.h>
#include "FMOPSOTopology.h"

template <class POT>
class FMOPSOAlgorithm : public eoPSO<POT>
{
public:
    /* Constructor without eoInitializerBase. Assume the initialization is done before running the algorithm
    * @param _continuator - An eoContinue that manages the stopping criterion and the checkpointing system
    * @param _eval - An eoEvalFunc: the evaluation performer
    * @param _velocity - An eoVelocity that defines how to compute the velocities
    * @param _flight - An eoFlight that defines how to make the particle flying: that means how
    * to modify the positions according to the velocities
    */
    FMOPSOAlgorithm(
            eoContinue<POT> &_continuator,
            eoVelocity<POT> &_velocity,
            eoFlight<POT> &_flight,
            std::vector<eoEvalFunc<POT>* > &m_eval_funcs,
            FMOPSOTopology<POT> &_topology) :
            continuator(_continuator),
            velocity(_velocity),
            flight(_flight),
            m_eval_funcs(m_eval_funcs),
            topology(_topology)
            {
                if(m_eval_funcs.size() != topology.getColumnas())
                    throw std::invalid_argument("Inconsistent ");
            }

    /// Apply a few iteration of flight to the population (=swarm).
    virtual void operator  () (eoPop < POT > &_pop)
    {
        try
        {
            // initializes the topology, velocity, best particle(s)
            do
            {
                // loop over all the particles for the current iteration
                for (unsigned idx = 0; idx < _pop.size (); idx++)
                {
                    // perform velocity evaluation
                    velocity (_pop[idx],idx);

                    // apply the flight
                    flight (_pop[idx]);

                    // evaluate the position
                    m_eval_funcs.at(idx % topology.getColumnas())->operator()(_pop[idx]);

                    // update the topology (particle and local/global best(s))
                    velocity.updateNeighborhood(_pop[idx],idx);
                }

            }
            while (continuator (_pop));

        }
        catch (std::exception & e)
        {
            std::string s = e.what ();
            s.append (" in FMOPSO");
            throw std::runtime_error (s);
        }

    }

protected:
    eoContinue < POT > &continuator;
    //eoEvalFunc < POT > &eval;
    eoVelocity < POT > &velocity;
    eoFlight < POT > &flight;
    FMOPSOTopology< POT > &topology;
    std::vector<eoEvalFunc<POT>* >& m_eval_funcs;
};


#endif //BI_OBJECTIVENRP_FMOPSOALGORITHM_H
