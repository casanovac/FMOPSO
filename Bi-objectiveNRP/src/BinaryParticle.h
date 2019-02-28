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
