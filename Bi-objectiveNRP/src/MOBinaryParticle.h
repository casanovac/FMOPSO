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
