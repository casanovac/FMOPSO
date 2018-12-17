//
// Created by carlos on 16/11/18.
//

#ifndef BI_OBJECTIVENRP_FMOPSOTOPOLOGY_H
#define BI_OBJECTIVENRP_FMOPSOTOPOLOGY_H


#include <eoTopology.h>
#include <eoPop.h>
#include <sstream>
#include "BinaryParticle.h"

template <class POT> class FMOPSOTopology : public eoTopology<POT>{
public:

    /**
     * Inicializa los atributos necesarios. FALTA INICIALIZAR LAS SUBTOPOLOGIAS (STAR) Y AGREGAR COMO MIEMBRO
     * LA FUNCION MULTIOBJETIVO
     * @param filas
     * @param columnas
     */
    FMOPSOTopology (unsigned filas, unsigned columnas, std::vector<eoEvalFunc<POT>* >& eval_funcs):isSetup(false), m_filas(filas), m_columnas(columnas), m_eval_funcs(eval_funcs)
    {

    }

    FMOPSOTopology(const FMOPSOTopology& anotherTopology)
    {
        isSetup = anotherTopology.isSetup;
        m_filas = anotherTopology.m_filas;
        m_columnas = anotherTopology.m_columnas;
        m_localNeighborhoods = anotherTopology.m_localNeighborhoods;
        m_eval_funcs = anotherTopology.m_eval_funcs;
    }

    void setup(const eoPop<POT> & _pop)
    {
        if (!isSetup){

            if(m_filas * m_columnas != _pop.size())
            {
                std::stringstream s;
                s << " Tamaño de la población inadecuado para esta topología FMOPSO. ";
                s << " Tamaño esperado es ";
                s << m_filas*m_columnas;
                s << " y se recibió ";
                s << _pop.size();
                throw std::invalid_argument (s.str());
            }

            for(unsigned int j = 0; j < m_columnas; j++)
            {
                // Construir una topología por "columna"
                eoSocialNeighborhood<POT> localNeighborhood;
                localNeighborhood.put(j);
                localNeighborhood.best(_pop.at(j));
                m_localNeighborhoods.push_back(localNeighborhood);
            }
            for(unsigned int i = 1; i < m_filas; i++)
            {
                for(unsigned int j = 0; j < m_columnas; j++)
                {
                    m_localNeighborhoods.at(j).put(i * m_columnas + j);
                    if(m_localNeighborhoods.at(j).best() < _pop.at(i*m_columnas+j))
                    {
                        m_localNeighborhoods.at(j).best(_pop.at(i*m_columnas+j));
                    }
                }
            }

            isSetup=true;
        }
        else
        {
            std::string s;
            s.append (" FMOPSO topology already setup ");
            throw std::runtime_error (s);
        }
    }

    void updateNeighborhood(POT & _po,unsigned _indice)
    {
        // update the best fitness of the particle
        if (_po.best() < _po.fitness())
        {
            _po.best(_po.fitness());
            _po.setBestObjectiveVectorValue(_po.objectiveVector());
            for(unsigned i=0;i<_po.size();i++)
                _po.bestPositions[i]=_po[i];
        }
        //unsigned fila = _indice / m_columnas;
        unsigned columna = _indice % m_columnas;
        // update the neighborhood best if the given particle is "better"
        if (m_localNeighborhoods.at(columna).best() < _po)
        {
            m_localNeighborhoods.at(columna).best(_po);
        }
        // update contiguous neighbourhoods if better
        if(columna > 0)
        {
            POT pot(_po);
            m_eval_funcs.at(columna - 1)->operator()(pot);
            pot.best(pot.fitness());
            if (m_localNeighborhoods.at(columna - 1).best() < pot)
            {
                for(unsigned i=0;i<pot.size();i++)
                    pot.bestPositions[i]=pot[i];
                m_localNeighborhoods.at(columna - 1).best(pot);
            }
        }
        if(columna < (m_columnas - 1))
        {
            POT pot(_po);
            m_eval_funcs.at(columna + 1)->operator()(pot);
            pot.best(pot.fitness());
            if (m_localNeighborhoods.at(columna + 1).best() < pot)
            {
                for(unsigned i=0;i<pot.size();i++)
                    pot.bestPositions[i]=pot[i];
                m_localNeighborhoods.at(columna + 1).best(pot);
            }
        }
    }

    /*void updateNeighborhood(eoPop<POT> &_pop)
    {
        // Acá hay que actualizar los mejores individuales (grupales)
        eoTopology<POT>::updateNeighborhood(_pop);
    }*/


    /**
     * Return the global best particle.
     * @param _indice - The indice of a particle in the population
     * @return POT & - The best particle in the neighborhood of the particle whose indice is _indice
     */
    POT & best (unsigned _indice)
    {
        return (this->m_localNeighborhoods.at(_indice % m_columnas).best());
    }

    /*POT &globalBest() override
    {
        POT& gbest = m_localNeighborhoods.at(0).best();
        for(eoSocialNeighborhood<POT> nghb: m_localNeighborhoods)
        {
            if(gbest.best().fitness() < nghb.best().best().fitness())
            {
                gbest = nghb.best();
            }
        }
        return gbest;
    }*/

    void globalBest(POT& best)
    {
        throw std::logic_error("globalBest not supported in FMOPSOTopology");
    }

    POT &globalBest() override
    {
        throw std::logic_error("globalBest not supported in FMOPSOTopology");
    }


    /**
      * Print the structure of the topology on the standard output.
      */
    void printOn()
    {
        std::cout << "Pareto Front Encountered:\n{\n" ;
        for (unsigned i=0;i< this->m_localNeighborhoods.size();i++)
            std::cout << i << ": " << this->m_localNeighborhoods.at(i).best() << std::endl;
        std::cout << "\n}" << std::endl;
    }

    std::vector<typename POT::ObjectiveVector> getParetoFront() const
    {
        std::vector<typename POT::ObjectiveVector> front;
        for(eoSocialNeighborhood<POT> neighborhood: m_localNeighborhoods)
        {
            front.push_back(neighborhood.best().getBestObjectiveVectorValue());
        }
        return front;
    }

    unsigned int getFilas() const {
        return m_filas;
    }

    unsigned int getColumnas() const {
        return m_columnas;
    }

private:
    bool isSetup;
    unsigned int m_filas, m_columnas;
    std::vector<eoSocialNeighborhood<POT> > m_localNeighborhoods;
    std::vector<eoEvalFunc<POT>* >& m_eval_funcs;
    //POT globalBestPOT;
};


#endif //BI_OBJECTIVENRP_FMOPSOTOPOLOGY_H
