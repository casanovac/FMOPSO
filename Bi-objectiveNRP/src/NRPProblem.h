//
// Created by carlos on 16/11/18.
//

#ifndef BI_OBJECTIVENRP_NRPINSTANCE_H
#define BI_OBJECTIVENRP_NRPINSTANCE_H

#include <vector>
#include <set>
#include <string>
#include <fstream>

class NRPProblem {
public:
    NRPProblem() = default;

    NRPProblem(const NRPProblem& anotherInstance)
    {
        this->requirementsCost = anotherInstance.requirementsCost;
        this->customersProfit = anotherInstance.customersProfit;
        this->precedenceRelation = anotherInstance.precedenceRelation;
        this->interestRelation = anotherInstance.interestRelation;
    }

    // TODO: check if fileName is valid
    void load(std::string fileName)
    {
        std::ifstream nrp1;
        std::string line;
        nrp1.open (fileName);
        int t;
        nrp1 >> t;

        //Armado del vector de requerimientos
        for (int i=0; i<t; i++)
        {
            int actualvl;
            nrp1 >> actualvl;
            for (int j=0; j<actualvl; j++)
            {
                int actualcost;
                nrp1 >> actualcost;
                this->requirementsCost.push_back(actualcost);
            }
        }

        //Armado del arreglo de pares con relaciones de precedencia
        unsigned int cantdp;
        nrp1 >> cantdp;

        for (int dep1 = 0; dep1<cantdp; dep1++)
        {
            int r1, r2;
            nrp1 >> r1 >> r2;
            std::pair <int,int> par =  std::make_pair(r1 - 1, r2 - 1);
            this->precedenceRelation.insert(par);
        }

        //Armado del vector de customers
        unsigned int cantcustomers;
        nrp1 >> cantcustomers;

        for (int customer = 0; customer<cantcustomers; customer++)
        {
            double profit;
            nrp1 >> profit;    //Agrego el valor de profit
            this->customersProfit.push_back(profit);
            int cantReqs;                                        //Defino esta variable para no perder el valor del request
            nrp1 >> cantReqs;

            for (int posVRL=0; posVRL < cantReqs; posVRL++)     //Defino el vector
            {
                int req;
                nrp1 >> req;
                this->interestRelation.insert(std::make_pair(customer, req - 1));

            }
        }

        nrp1.close();
    }

    const std::vector<double> &getRequirementsCost() const {
        return requirementsCost;
    }

    const std::vector<double> &getCustomersProfit() const {
        return customersProfit;
    }

    const std::set<std::pair<unsigned int, unsigned int>> &getPrecedenceRelation() const {
        return precedenceRelation;
    }

    const std::set<std::pair<unsigned int, unsigned int>> &getInterestRelation() const {
        return interestRelation;
    }

    const void printOn(std::ostream& os)
    {
        os << "Requirements: " << this->requirementsCost.size() << std::endl;
        os << "Requirements cost: \n";
        for (double reqCost: this->requirementsCost)
        {
            os << reqCost << " ";
        }
        os << std::endl;
        os << "Customers: " << this->customersProfit.size() << std::endl;
        os << "Customers profit: \n";
        for (double ctmProf: this->customersProfit)
        {
            os << ctmProf << " ";
        }
        os << std::endl;
        os << "Precedence Relation: " << this->precedenceRelation.size() << std::endl;
        for(std::set<std::pair<unsigned, unsigned> >::iterator it = precedenceRelation.begin(); it != precedenceRelation.end(); it++)
        {
            os << "Requirement " << it->first << " mandatory for requirement " << it->second << "\n";
        }
        os << std::endl;
        os << "Interest Relation: " << this->interestRelation.size() << std::endl;
        for(std::set<std::pair<unsigned, unsigned> >::iterator it = interestRelation.begin(); it != interestRelation.end(); it++)
        {
            os << "Customer " << it->first << " has interest in requirement " << it->second << "\n";
        }

    }

private:
    std::vector<double> requirementsCost;
    std::vector<double> customersProfit;
    std::set<std::pair<unsigned, unsigned> > precedenceRelation;
    std::set<std::pair<unsigned, unsigned> > interestRelation;
};


#endif //BI_OBJECTIVENRP_NRPINSTANCE_H
