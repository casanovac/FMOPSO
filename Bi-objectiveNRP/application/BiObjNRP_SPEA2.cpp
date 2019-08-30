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
// Created by carlos on 06/12/18.
//
#include <iostream>
#include <moeo>
#include <distance/moeoDistance.h>
#include <distance/moeoEuclideanDistance.h>
#include <NRP/NRPProblem.h>
#include <NRP/CostNRPAttribute.h>
#include <NRP/ProfitNRPAttribute.h>
#include <NRP/BiObjFuzzyNRPFitnessFunction.h>
#include <NRP/BiObjNRPVectorTraits.h>
#include <NRP/BiObjNRPMOEval.h>
#include <metric/moeoHyperVolumeMetric.h>
#include <NRP/NRPMutation.h>
#include <NRP/NRPCrossover.h>
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
    parser.processParam( numberOfIndi, "SPEA2 Params" );
    unsigned int number_of_individuals = numberOfIndi.value();

    eoValueParam<unsigned int> archiveSize(300, "archive_size", "Tamaño del archivo", 'A');
    parser.processParam( archiveSize, "SPEA2 Params" );
    unsigned int archive_size = archiveSize.value();

    eoValueParam<double> crossoverProbabilityParam(0.6, "CrossoverP", "Probabilidad de cruzamiento", 'X');
    parser.processParam( crossoverProbabilityParam, "SPEA2 Params" );
    double Pc = crossoverProbabilityParam.value();

    eoValueParam<double> mutationProbabilityParam(0.1, "MutationP", "Probabilidad de mutación", 'M');
    parser.processParam( mutationProbabilityParam, "SPEA2 Params" );
    double Pm = mutationProbabilityParam.value();

    eoValueParam<double> maxTimeParam(30.0, "Max_Time", "Tiempo máximo a correr el algoritmo en segundos (s)", 'T');
    parser.processParam( maxTimeParam, "SPEA2 Params" );
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
    instance.load("nrp1.txt");
    instance.printOn(std::cout);

    PartiallyOrderedSetFlight<MOBinaryParticle<BiObjNRPObjectiveVector>> flight(instance.getPrecedenceRelation());

    NRPMutation<moeoBitVector<BiObjNRPObjectiveVector>> mutation(instance.getPrecedenceRelation());
    NRPCrossover<moeoBitVector<BiObjNRPObjectiveVector>> crossover;
    eoPop<moeoBitVector<BiObjNRPObjectiveVector> > pop;

    eoUniformGenerator<bool> sGen(0, 1);
    eoVelocityInitFixedLength<MOBinaryParticle<BiObjNRPObjectiveVector> > veloRandom(
            instance.getRequirementsCost().size(), sGen);

    BiObjNRPMOEval<moeoBitVector<BiObjNRPObjectiveVector>> eval("nrp1.txt");

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
    moeoSPEA2Archive<moeoBitVector<BiObjNRPObjectiveVector> > arch(archive_size);
    moeoSPEA2<moeoBitVector<BiObjNRPObjectiveVector>> spea2(timeContinue, eval, sgaGenOp, arch);

    spea2(pop);

// extract first front of the final population using an moeoArchive (this is the output of nsgaII)

    arch(pop);

// printing of the final archive
    std::cout << "Final Archive" << std::endl;
    arch.sortedPrintOn(std::cout);
    std::cout << std::endl;

    std::vector<BiObjNRPObjectiveVector> completeFront;
    for (moeoBitVector<BiObjNRPObjectiveVector> individual: pop)
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

    std::vector<eoRealInterval> bounds(2);
    for (unsigned i = 0; i < 2; i++)
        bounds[i] = eoRealInterval(leftRef[i], rightRef[i]);

    moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(refPoint, bounds);

//moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(true, 1.0);
    std::vector<BiObjNRPObjectiveVector> extremePoints;
    extremePoints.push_back(BiObjNRPObjectiveVector(leftRef));
    extremePoints.push_back(BiObjNRPObjectiveVector(rightRef));
//hypervolume00.setup(extremePoints);
    std::cout << hypervolume00(extremePoints) << std::endl;
//moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(true, 1.0);
//moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(false, refPoint);

//hypervolume00.setup(completeFront);
    std::cout << "El hipervolumen del frente logrado por el algoritmo es: " << hypervolume00(completeFront)
              << std::endl;
}