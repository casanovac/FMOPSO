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
        std::ifstream file;
        std::string line;
        file.open (fileName);

        //Build requirements' vector
        int n_levels;           // Number of levels
        int n_req;              // Number of requirements in each level
        int cost;               // Cost for each requirement
        file >> n_levels;
        for (int lvl=0; lvl<n_levels; lvl++)
        {
            file >> n_req;
            for (int req=0; req<n_req; req++)
            {
                file >> cost;
                this->requirementsCost.push_back(cost);
            }
        }

        //Build dependencies' pairs vector
        unsigned int n_dependencies;    // Number of dependencies
        int req1, req2;                 // Pair of requirements
        file >> n_dependencies;
        for (int dep = 0; dep<n_dependencies; dep++)
        {
            file >> req1 >> req2;
            std::pair <int,int> pair =  std::make_pair(req1 - 1, req2 - 1);
            this->precedenceRelation.insert(pair);
        }

        // Build customers' vector

        unsigned int n_customers; // Number of customers
        double profit;            // Profit provided by each customer if their requirements are satisfied
        int n_demand;             // Amount of requirements demanded by the current customer
        int demanded_req;         // Loop variable for each requirement demanded by the current customer
        file >> n_customers;
        for (int customer = 0; customer<n_customers; customer++)
        {
            file >> profit;
            this->customersProfit.push_back(profit);
            file >> n_demand;
            for (int posVRL=0; posVRL < n_demand; posVRL++)
            {
                file >> demanded_req;
                this->interestRelation.insert(std::make_pair(customer, demanded_req - 1));
            }
        }
        file.close();
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
