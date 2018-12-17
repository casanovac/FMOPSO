//
// Created by carlos on 26/11/18.
//

#ifndef BI_OBJECTIVENRP_BIOBJFUZZYNRPFITNESS_H
#define BI_OBJECTIVENRP_BIOBJFUZZYNRPFITNESS_H


#include <eoScalarFitness.h>
#include <ostream>

class BiObjFuzzyNRPFitness : public eoScalarFitness<float, std::less<float>>{
public:
    BiObjFuzzyNRPFitness() {}
    BiObjFuzzyNRPFitness(const BiObjFuzzyNRPFitness& other) : value(other.value), cost(other.cost), profit(other.profit),  costMembership(other.costMembership), profitMembership(other.profitMembership){}
    //BiObjFuzzyNRPFitness(const float& v) : value(v) {}

    BiObjFuzzyNRPFitness & operator=(const BiObjFuzzyNRPFitness & other)
    {
        value = other.value;
        cost = other.cost;
        profit = other.profit;
        costMembership = other.costMembership;
        profitMembership = other.profitMembership;
        return *this;
    }
    /*eoScalarFitness& operator=(const float& v)
    { value = v; return *this; }*/

    /** Conversion operator: it permits to use a fitness instance as  its  scalar
     * type, if needed. For example, this is possible:
     *     eoScalarFitness<double,std::less<double> > fit;
     *     double val = 1.0;
     *     fit = val;
     *     val = fit;
     */
    //operator float(void) const { return value; }

    /// Comparison, using less by default
    bool operator<(const BiObjFuzzyNRPFitness & other) const
    { return std::less<float>()(value, other.value); }

    bool operator>(const BiObjFuzzyNRPFitness & other) const
    { return std::less<float>()(other.value, value); }

    /// Comparison, using less by default
    bool operator<=(const BiObjFuzzyNRPFitness & other) const
    { return !(other < *this); }

    bool operator>=(const BiObjFuzzyNRPFitness & other) const
    { return !(*this < other); }

    /// Comparison, using less by default
    //  needed for MSVC 8 (MSVC 2005) added by J.Eggermont 20-11-2006
    /*bool operator<(const ScalarType& other) const
    { return Compare()(value, other); }*/
    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        BiObjFuzzyNRPFitness::cost = cost;
    }

    double getProfit() const {
        return profit;
    }

    void setProfit(double profit) {
        BiObjFuzzyNRPFitness::profit = profit;
    }

    float getCostMembership() const {
        return costMembership;
    }

    void setCostMembership(float costMembership) {
        BiObjFuzzyNRPFitness::costMembership = costMembership;
    }

    float getProfitMembership() const {
        return profitMembership;
    }

    void setProfitMembership(float profitMembership) {
        BiObjFuzzyNRPFitness::profitMembership = profitMembership;
    }

    float getValue() const {
        return value;
    }

    void setValue(float value) {
        BiObjFuzzyNRPFitness::value = value;
    }

protected:
    double cost, profit;
    float costMembership, profitMembership, value;
};

std::ostream& operator<<(std::ostream& os, const BiObjFuzzyNRPFitness& f)
{
    os << "Fitness: " << f.getValue()<< " = min(mu_Cost(" << f.getCost() << ") = " << f.getCostMembership() << ", mu_Profit(" << f.getProfit() << ") = " << f.getProfitMembership() << ")}";
    return os;
}

#endif //BI_OBJECTIVENRP_BIOBJFUZZYNRPFITNESS_H
