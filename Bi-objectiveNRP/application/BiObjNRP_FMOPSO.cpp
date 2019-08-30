//
// Created by carlos on 06/12/18.
//
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
#include <iostream>
#include <eo>
#include <NRP/NRPProblem.h>
#include <NRP/CostNRPAttribute.h>
#include <eoScalarFitness.h>
#include <NRP/NRPEvalAttributeWrapper.h>
#include <PartiallyOrderedSetFlight.h>
#include <BinaryVelocity.h>
#include <VonNeumannTopology.h>
#include <NRP/ProfitNRPAttribute.h>
#include <Fuzzy/ExpWeightedFuzzyNumberDecorator.h>
#include <FMOPSO/FMOPSOBinaryVelocity.h>
#include <FMOPSO/FMOPSOAlgorithm.h>
#include <NRP/BiObjFuzzyNRPFitnessFunction.h>
#include <NRP/BiObjNRPVectorTraits.h>
#include <MOBinaryParticle.h>
#include <NRP/BiObjNRPMOEval.h>
#include <Fuzzy/FuzzyFitnessSingleObjectivization.h>
#include <metric/moeoHyperVolumeMetric.h>
#include <NRP/NRPMutation.h>
#include <NRP/NRPCrossover.h>
#include <algo/moeoNSGAII.h>
#include <core/moeoBitVector.h>
#include <archive/moeoUnboundedArchive.h>

int main(int argc, char* argv[])
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

    eoValueParam<unsigned int> filasParam(10, "filas", "Filas del arreglo bidimensional de partículas del FMOPSO", 'F');
    parser.processParam( filasParam, "FMOPSO Params" );
    unsigned int filas = filasParam.value();

    eoValueParam<unsigned int> columnasParam(300, "columnas", "Columnas del arreglo bidimensional de partículas del FMOPSO", 'C');
    parser.processParam( columnasParam, "FMOPSO Params" );
    unsigned int columnas = columnasParam.value();

    eoValueParam<double> maxTimeParam(30.0, "max_time", "Tiempo máximo a correr el algoritmo en segundos (s)", 'T');
    parser.processParam( maxTimeParam, "FMOPSO Params" );
    double maxSeconds = maxTimeParam.value();
    // END PARAMETERS
    std::string str_status = parser.ProgramName() + ".status";
    eoValueParam<std::string> statusParam(str_status.c_str(), "status","Status file",'S');
    parser.processParam( statusParam, "Persistence" );

    unsigned int n = filas*columnas;

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
    eoPop<MOBinaryParticle<BiObjNRPObjectiveVector> > pop;

    eoUniformGenerator < bool >sGen (0, 1);
    eoVelocityInitFixedLength < MOBinaryParticle<BiObjNRPObjectiveVector> > veloRandom (instance.getRequirementsCost().size(), sGen);

    BiObjNRPMOEval<MOBinaryParticle<BiObjNRPObjectiveVector>> eval(instance_filename);

    std::vector<eoEvalFunc<MOBinaryParticle<BiObjNRPObjectiveVector> >* > eval_funcs;
    //std::vector<BiObjFuzzyNRPFitnessFunction> eval_funcs;
    std::vector<double> leftRef;
    std::vector<double> rightRef;
    leftRef.push_back(min_profit);
    leftRef.push_back(min_cost);
    rightRef.push_back(max_profit);
    rightRef.push_back(max_cost);

    for(unsigned int j = 0; j < columnas; j++)
    {
        double cost_exp = 2.0 * (double) j / (double) (columnas-1);

        std::vector<double> expW;
        expW.push_back(2-cost_exp);
        expW.push_back(cost_exp);
        eval_funcs.push_back(new FuzzyFitnessSingleObjectivization<MOBinaryParticle<BiObjNRPObjectiveVector>>(&eval, leftRef, rightRef, expW));
    }

    FMOPSOTopology<MOBinaryParticle<BiObjNRPObjectiveVector>> topology(filas, columnas, eval_funcs);

    FMOPSOBinaryVelocity<MOBinaryParticle<BiObjNRPObjectiveVector>> vel(topology, rng);

    // Inicializamos a mano las velocidades y las aplicamos con flight
    for(unsigned int i = 0; i < filas*columnas; i++)
    {
        MOBinaryParticle<BiObjNRPObjectiveVector> part(instance.getRequirementsCost().size());
        veloRandom(part);
        flight(part);
        for(unsigned int j = 0; j < part.size(); j++)
        {
            part.bestPositions[j] = part[j];
        }
        eval_funcs.at(i % columnas)->operator()(part);
        part.best(part.fitness());
        part.setBestObjectiveVectorValue(part.objectiveVector());
        pop.push_back(part);
    }

    topology.setup(pop);
    //eoGenContinue<MOBinaryParticle<BiObjNRPObjectiveVector> > genContinue(GEN);
    eoTimeContinue<MOBinaryParticle<BiObjNRPObjectiveVector>> timeContinue(maxSeconds);
    FMOPSOAlgorithm<MOBinaryParticle<BiObjNRPObjectiveVector> > pso1(timeContinue, vel, flight, eval_funcs, topology);

    //std::cout << "Antes del PSO" << std::endl;
    //pop.printOn(std::cout);

    pso1(pop);

    //std::cout << "Después del PSO" << std::endl;
    //pop.printOn(std::cout);
    std::cout << "\n\nMejor partícula encontrada" << std::endl;
    std::cout << pop.best_element() << std::endl;
    std::cout << "Mejores grupales:" << std::endl;
    topology.printOn();

    std::cout << "\n\n[";
    std::vector<BiObjNRPObjectiveVector> completeFront;
    std::vector<BiObjNRPObjectiveVector> completeNonBestFront;
    for(MOBinaryParticle<BiObjNRPObjectiveVector> individual: pop)
    {
        //std::cout << individual.getBestObjectiveVectorValue() << ";" << std::endl;
        completeFront.push_back(individual.getBestObjectiveVectorValue());
        completeNonBestFront.push_back(individual.objectiveVector());
    }
    std::cout << "];";

    for(int j = columnas-1; j >= 0; j--)
    {
        delete eval_funcs.at(j);
    }
    eval_funcs.clear();

    BiObjNRPObjectiveVector refPoint;
    refPoint[0] = 0.0;
    refPoint[1] = 1.0;

    std::vector < eoRealInterval > bounds(2);
    for(unsigned i = 0; i < 2; i++)
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
    std::vector<BiObjNRPObjectiveVector> reducedFront = topology.getParetoFront();

    //hypervolume00.setup(reducedFront);
    std::cout << "El hipervolumen del frente (reducido) logrado por el algoritmo es: " << hypervolume00(reducedFront) << std::endl;

    //hypervolume00.setup(completeFront);
    std::cout << "El hipervolumen del frente (completo) logrado por el algoritmo es: " << hypervolume00(completeFront) << std::endl;

    //hypervolume00.setup(completeNonBestFront);
    std::cout << "El hipervolumen del frente (completo no mejores) logrado por el algoritmo es: " << hypervolume00(completeNonBestFront) << std::endl;

    completeFront.reserve(completeFront.size()+completeNonBestFront.size());
    completeFront.insert(completeFront.end(), completeNonBestFront.begin(), completeNonBestFront.end());

    //hypervolume00.setup(completeFront);
    std::cout << "El hipervolumen del frente (combinado) logrado por el algoritmo es: " << hypervolume00(completeFront) << std::endl;

    moeoUnboundedArchive<MOBinaryParticle<BiObjNRPObjectiveVector> > arch;
    arch(pop);
    for(MOBinaryParticle<BiObjNRPObjectiveVector> individual: pop)
    {
        MOBinaryParticle<BiObjNRPObjectiveVector> bestPos(individual);
        bestPos.position(individual.bestPositions);
        bestPos.objectiveVector(individual.getBestObjectiveVectorValue());
        bestPos.fitness(individual.best());
        arch(bestPos);
    }

    std::cout << "\n\nArchivo logrado:" << std::endl;
    arch.printOn(std::cout);
    std::cout << "HV\t\t\tPFS" << std::endl;
    std::cout << hypervolume00(completeFront) << "\t" << arch.size() << std::endl;
}