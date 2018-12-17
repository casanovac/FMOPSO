//
// Created by carlos on 21/11/18.
//

#ifndef BI_OBJECTIVENRP_VONNEUMANNTOPOLOGY_H
#define BI_OBJECTIVENRP_VONNEUMANNTOPOLOGY_H

#include <eoTopology.h>
#include <eoPop.h>
#include <eoSocialNeighborhood.h>
#include <sstream>

template <class POT>
class VonNeumannTopology : public eoTopology<POT>{
public:
    VonNeumannTopology(unsigned filas, unsigned columnas) : isSetup(false), m_filas(filas), m_columnas(columnas) {};

    void setup(const eoPop <POT> &_pop) override {

        if(isSetup)
        {
            std::string s;
            s.append (" VonNeumann topology already setup ");
            throw std::logic_error (s);
        }
        if(m_filas * m_columnas != _pop.size())
        {
            std::stringstream s;
            s << " Inconsistent population size, must be ";
            s << m_filas * m_columnas;
            s << " and received ";
            s << _pop.size();
            throw std::invalid_argument (s.str());
        }
        for(unsigned int i = 0; i < m_filas; i++)
        {
            for(unsigned int j = 0; j < m_columnas; j++)
            {
                eoSocialNeighborhood<POT> localNeighborhood;
                unsigned pop_index = i * m_columnas + j;
                //localNeighborhood.put(pop_index);
                //localNeighborhood.best(_pop.at(pop_index));

                unsigned upNghbr = (_pop.size() + pop_index - m_columnas) % _pop.size();
                unsigned downNghbr = (_pop.size() + pop_index + m_columnas) % _pop.size();
                unsigned leftNghbr = (_pop.size() + pop_index - 1) % _pop.size();
                unsigned rightNghbr = (_pop.size() + pop_index + 1) % _pop.size();

                localNeighborhood.put(upNghbr);
                localNeighborhood.put(downNghbr);
                localNeighborhood.put(leftNghbr);
                localNeighborhood.put(rightNghbr);

                POT best = _pop.at(upNghbr);
                for(unsigned int i = 1; i < 4; i++)
                {
                    unsigned pop_index = localNeighborhood.get(i);
                    if(best < _pop.at(pop_index))
                        best = _pop.at(pop_index);
                }
                localNeighborhood.best(best);
                m_neighborhoods.push_back(localNeighborhood);
            }
        }
        globalBestPOT = _pop.best_element();
    }

    void updateNeighborhood(POT &_po, unsigned int i) override
    {
        // update the best fitness of the particle
        if (_po.best() < _po.fitness())
        {
            _po.best(_po.fitness());
            for(unsigned i=0;i<_po.size();i++)
                _po.bestPositions[i]=_po[i];
        }
        // update the neighbors best if the given particle is "better"
        std::vector<unsigned int> informatives = m_neighborhoods.at(i).getInformatives();
        for(unsigned int nghb: informatives)
        {
            if(m_neighborhoods.at(nghb).best() < _po)
            {
                m_neighborhoods.at(nghb).best(_po);
            }
        }
        // update global best if corresponds
        if(this->globalBest() < _po)
            this->globalBest(_po);
    }

    POT &best(unsigned int i) override
    {
        return m_neighborhoods.at(i).best();
    }

    void printOn() override {

    }

    void globalBest(POT& best)
    {
        globalBestPOT = best;
    }

    POT &globalBest() override
    {
        return globalBestPOT;
    }

private:
    bool isSetup;
    unsigned m_filas, m_columnas;
    std::vector<eoSocialNeighborhood<POT> > m_neighborhoods;
    POT globalBestPOT;
};


#endif //BI_OBJECTIVENRP_VONNEUMANNTOPOLOGY_H
