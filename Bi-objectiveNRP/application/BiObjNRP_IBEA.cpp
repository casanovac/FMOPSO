//
// Created by carlos on 06/12/18.
//
#include <iostream>
#include <moeo>
#include <distance/moeoDistance.h>
#include <distance/moeoEuclideanDistance.h>
#include <NRPProblem.h>
#include <CostNRPAttribute.h>
#include <ProfitNRPAttribute.h>
#include <BiObjFuzzyNRPFitnessFunction.h>
#include <BiObjNRPVectorTraits.h>
#include <BiObjNRPMOEval.h>
#include <metric/moeoHyperVolumeMetric.h>
#include <NRPMutation.h>
#include <NRPCrossover.h>
#include <core/moeoBitVector.h>
#include <algo/moeoSPEA2.h>
#include <PartiallyOrderedSetFlight.h>

int main(int argc, char *argv[])
{
    eoParser parser(argc, argv);
    // PARAMETERS
    eoValueParam<std::string> instanceFilenameParam("nrp1.txt", "instance_filename", "Nombre del archivo que contiene la instancia NRP a resolver", 'I');
    parser.processParam( instanceFilenameParam, "NRP Instance Params" );
    std::string instance_filename = instanceFilenameParam.value();

    eoValueParam<double> minProfit(0.0, "min_profit", "Mínimo beneficio del frente", 'p');
    parser.processParam( minProfit, "NRP Instance Params" );
    double min_profit = minProfit.value();
    eoValueParam<double> maxProfit(2909.0, "max_profit", "Máximo beneficio del frente", 'P');
    parser.processParam( maxProfit, "NRP Instance Params" );
    double max_profit = maxProfit.value();

    eoValueParam<double> minCost(0.0, "min_cost", "Mínimo costo del frente", 'c');
    parser.processParam( minCost, "NRP Instance Params" );
    double min_cost = minCost.value();
    eoValueParam<double> maxCost(787.0, "max_cost", "Máximo costo del frente", 'C');
    parser.processParam( maxCost, "NRP Instance Params" );
    double max_cost = maxCost.value();

    eoValueParam<unsigned int> numberOfIndi(300, "Individuals", "Tamaño de la población, cantidad de individuos", 'N');
    parser.processParam( numberOfIndi, "IBEA Params" );
    unsigned int number_of_individuals = numberOfIndi.value();

    eoValueParam<double> crossoverProbabilityParam(0.6, "CrossoverP", "Probabilidad de cruzamiento", 'X');
    parser.processParam( crossoverProbabilityParam, "IBEA Params" );
    double Pc = crossoverProbabilityParam.value();

    eoValueParam<double> mutationProbabilityParam(0.1, "MutationP", "Probabilidad de mutación", 'M');
    parser.processParam( mutationProbabilityParam, "IBEA Params" );
    double Pm = mutationProbabilityParam.value();

    eoValueParam<double> maxTimeParam(30.0, "Max_Time", "Tiempo máximo a correr el algoritmo en segundos (s)", 'T');
    parser.processParam( maxTimeParam, "IBEA Params" );
    double maxSeconds = maxTimeParam.value();
    // END PARAMETERS
    std::string str_status = parser.ProgramName() + ".status";
    eoValueParam<std::string> statusParam(str_status.c_str(), "status","Status file",'S');
    parser.processParam( statusParam, "Persistence" );

    if (parser.userNeedsHelp())
    {
        parser.printHelp(std::cout);
        exit(1);
    }

    if (statusParam.value() != "")
    {
        std::ofstream os(statusParam.value().c_str());
        os << parser;
    }

    NRPProblem instance;
    instance.load(instance_filename);
    instance.printOn(std::cout);

    PartiallyOrderedSetFlight<MOBinaryParticle<BiObjNRPObjectiveVector>> flight(instance.getPrecedenceRelation());

    NRPMutation<moeoBitVector<BiObjNRPObjectiveVector>> mutation(instance.getPrecedenceRelation());
    NRPCrossover<moeoBitVector<BiObjNRPObjectiveVector>> crossover;
    eoPop<moeoBitVector<BiObjNRPObjectiveVector> > pop;

    eoUniformGenerator<bool> sGen(0, 1);
    eoVelocityInitFixedLength<MOBinaryParticle<BiObjNRPObjectiveVector> > veloRandom(
            instance.getRequirementsCost().size(), sGen);

    BiObjNRPMOEval<moeoBitVector<BiObjNRPObjectiveVector>> eval(instance_filename);

// Inicializamos a mano las velocidades y las aplicamos con flight
    for (unsigned int i = 0; i < number_of_individuals; i++)
    {
        MOBinaryParticle<BiObjNRPObjectiveVector> part(instance.getRequirementsCost().size());
        veloRandom(part);
        flight(part);
        moeoBitVector<BiObjNRPObjectiveVector> ind;
        ind.assign(part.begin(), part.end());
        eval(ind);
        pop.push_back(ind);
    }

    pop.printOn(std::cout);

    eoTimeContinue<moeoBitVector<BiObjNRPObjectiveVector>> timeContinue(maxSeconds);
    eoSGAGenOp<moeoBitVector<BiObjNRPObjectiveVector> > sgaGenOp(crossover, Pc, mutation, Pm);
    moeoAdditiveEpsilonBinaryMetric<BiObjNRPObjectiveVector> additiveEpsilonBinaryMetric; // Hypervolume Binary Metric no funciona con maximizaciones, a lo mejor se puede implementar y enviar para que lo agreguen
    moeoIBEA<moeoBitVector<BiObjNRPObjectiveVector>> ibea(timeContinue, eval, sgaGenOp, additiveEpsilonBinaryMetric);
    ibea(pop);

// extract first front of the final population using an moeoArchive (this is the output of nsgaII)
    moeoUnboundedArchive<moeoBitVector<BiObjNRPObjectiveVector> > arch;
    arch(pop);


// printing of the final archive
    std::cout << "Final Archive" << std::endl;
    arch.sortedPrintOn(std::cout);
    std::cout << std::endl;

    std::vector<BiObjNRPObjectiveVector> completeFront;
    for (moeoBitVector<BiObjNRPObjectiveVector> individual: arch)
    {
        std::cout << individual.objectiveVector() << ";" << std::endl;
        completeFront.push_back(individual.objectiveVector());
    }
    std::cout << "];";

    BiObjNRPObjectiveVector refPoint;
    refPoint[0] = 0.0;
    refPoint[1] = 1.0;

    std::vector<double> leftRef;
    std::vector<double> rightRef;
    leftRef.push_back(min_profit);
    leftRef.push_back(min_cost);
    rightRef.push_back(max_profit);
    rightRef.push_back(max_cost);

    std::cout << max_profit << std::endl;

    std::vector<eoRealInterval> bounds(2);
    for (unsigned i = 0; i < 2; i++)
        bounds[i] = eoRealInterval(leftRef[i], rightRef[i]);

    moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(refPoint, bounds);

//moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(true, 1.0);
    std::vector<BiObjNRPObjectiveVector> extremePoints;
    extremePoints.push_back(BiObjNRPObjectiveVector(leftRef));
    extremePoints.push_back(BiObjNRPObjectiveVector(rightRef));
//hypervolume00.setup(extremePoints);
    std::cout << "\n" << hypervolume00(extremePoints) << std::endl;

//moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(true, 1.0);
//moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(false, refPoint);

//hypervolume00.setup(completeFront);

    std::cout << "HV\t\t\tPFS" << std::endl;
    std::cout << hypervolume00(completeFront) << "\t" << arch.size() << std::endl;
}