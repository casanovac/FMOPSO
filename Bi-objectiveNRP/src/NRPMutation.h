//
// Created by carlos on 04/12/18.
//

#ifndef BI_OBJECTIVENRP_NRPMUTATION_H
#define BI_OBJECTIVENRP_NRPMUTATION_H


#include <eoOp.h>
#include <set>
#include <map>

template <class MOEOT>
class NRPMutation : public eoMonOp<MOEOT>
{
public:
    NRPMutation(const std::set<std::pair<unsigned int, unsigned int> > &partialOrderRelation)
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

    bool operator()(MOEOT &a1) override
    {
        // Choose at random an index, flip value and all its preds/sucs
        unsigned int pos = rng.random(a1.size());
        if(a1[pos])
            deactivateCascaded(a1, pos);
        else
            activateCascaded(a1, pos);
        return true;
    }

protected:

    void activateCascaded(MOEOT& position, unsigned index)
    {
        // Poner en true el valor en index
        position[index] = true;
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

    void deactivateCascaded(MOEOT& position, unsigned index)
    {
        // Poner en false el valor en index
        position[index] = false;

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
};


#endif //BI_OBJECTIVENRP_NRPMUTATION_H
