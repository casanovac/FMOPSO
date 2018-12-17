//
// Created by carlos on 16/11/18.
//

#ifndef BI_OBJECTIVENRP_PARTIALLYORDEREDSETFLIGHT_H
#define BI_OBJECTIVENRP_PARTIALLYORDEREDSETFLIGHT_H


#include <eoFlight.h>
#include <set>
#include <map>
#include <boost/iterator/counting_iterator.hpp>
#include "BinaryParticle.h"

template <class POT> class PartiallyOrderedSetFlight : public eoFlight<POT> {
public:
    PartiallyOrderedSetFlight(const std::set<std::pair<unsigned int, unsigned int> > &partialOrderRelation)
            : partialOrderRelation(partialOrderRelation)
    {
        for(std::set<std::pair<unsigned int, unsigned int>>::const_iterator it = partialOrderRelation.begin();
            it != partialOrderRelation.end(); it++)
        {
            // acá suponemos que las precedencias vienen dadas según la relación xRy <-> x se debe ejecutar antes que y
            succesors.insert(*it);
            predecesors.insert(std::pair<unsigned int, unsigned int>(it->second, it->first));
        }
    }

    void operator()(POT &_bp) override {
        std::vector<bool> newX = _bp;
        remaining_positions.clear();
        auto hint = remaining_positions.begin();
        for(unsigned int i = 0; i < _bp.velocities.size(); i++)
        {
            if(_bp.velocities.at(i))
            {
                hint = remaining_positions.insert(hint, i);
            }
        }
        /*for(unsigned int i = 0; i < _bp.size(); i++)
        {
            if(_bp.velocities.at(i))
            {
                if(!_bp.at(i))
                {
                    activateCascaded(newX, i);
                }
                else
                {
                    deactivateCascaded(newX, i);
                }
            }
        }*/
        while(!remaining_positions.empty())
        {
            unsigned int pos = *remaining_positions.begin();
            if(_bp.velocities.at(pos))
            {
                if(!_bp.at(pos))
                {
                    activateCascaded(newX, pos);
                }
                else
                {
                    deactivateCascaded(newX, pos);
                }
            }
        }
        _bp.position(newX);
        _bp.invalidate();
    }

protected:

    void activateCascaded(std::vector<bool>& position, unsigned index)
    {
        // Poner en true el valor en index
        position[index] = true;
        remaining_positions.erase(index);
        // Hallar los predecesores
        std::pair<std::multimap<unsigned int, unsigned int>::iterator, std::multimap<unsigned int, unsigned int>::iterator > predecesors = this->predecesors.equal_range(index);

        // Para todos los predecesores en false llamar recursivamente a este método
        for (std::multimap<unsigned int,unsigned int>::iterator it=predecesors.first; it!=predecesors.second; ++it)
        {
            unsigned int predecesor = it->second;
            if(!position.at(predecesor))
                activateCascaded(position, predecesor);
        }
    }

    void deactivateCascaded(std::vector<bool>& position, unsigned index)
    {
        // Poner en false el valor en index
        position[index] = false;
        remaining_positions.erase(index);
        // Hallar los sucesores
        std::pair<std::multimap<unsigned int, unsigned int>::iterator, std::multimap<unsigned int, unsigned int>::iterator > succesors = this->succesors.equal_range(index);

        // Para todos los sucesores en true llamar recursivamente a este método
        for (std::multimap<unsigned int,unsigned int>::iterator it=succesors.first; it!=succesors.second; ++it)
        {
            unsigned int succesor = it->second;
            if(position.at(succesor))
                deactivateCascaded(position, succesor);
        }
    }
private:
    std::set<std::pair<unsigned int, unsigned int> > partialOrderRelation;
    // se podría poner dos maps de predecesores y sucesores
    std::multimap<unsigned int, unsigned int > predecesors;
    std::multimap<unsigned int, unsigned int > succesors;
    std::set<int> remaining_positions;
};


#endif //BI_OBJECTIVENRP_PARTIALLYORDEREDSETFLIGHT_H
