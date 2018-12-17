//
// Created by carlos on 15/11/18.
//
#include <iostream>
#include <eo>
#include <NRPProblem.h>
#include <CostNRPAttribute.h>
#include <eoScalarFitness.h>
#include <NRPEvalAttributeWrapper.h>
#include <PartiallyOrderedSetFlight.h>
#include <BinaryVelocity.h>
#include <VonNeumannTopology.h>
#include <ProfitNRPAttribute.h>
#include <ExpWeightedFuzzyNumberDecorator.h>
#include <FMOPSOBinaryVelocity.h>
#include <FMOPSOAlgorithm.h>
#include <BiObjFuzzyNRPFitnessFunction.h>
#include <BiObjNRPVectorTraits.h>
#include <MOBinaryParticle.h>
#include <BiObjNRPMOEval.h>
#include <FuzzyFitnessSingleObjectivization.h>
#include <metric/moeoHyperVolumeMetric.h>
#include <NRPMutation.h>
#include <NRPCrossover.h>
#include <algo/moeoNSGAII.h>
#include <core/moeoBitVector.h>
#include <archive/moeoUnboundedArchive.h>

#define FILAS 25
#define COLUMNAS 25
#define N FILAS*COLUMNAS
#define GEN 100

int main(int argc, char* argv[])
{
    //ExpWeightedLinearMonotonicFuzzyNumber fn(LinearMonotonicFuzzyNumber(2.0, 4.0, LinearMonotonicFuzzyNumber::ASCENDING), 2.0);


    NRPProblem instance;
    instance.load("nrp2.txt");
    instance.printOn(std::cout);

    CostNRPAttribute cost(instance);
    ProfitNRPAttribute profit(instance);
    NRPEvalAttributeWrapper<BinaryParticle<eoMinimizingFitness>> evalFunction(&cost);
    NRPEvalAttributeWrapper<BinaryParticle<eoMaximizingFitness>> evalFunction2(&profit);

    //BinaryParticle<eoMinimizingFitness> particle(instance.getRequirementsCost().size(), true);
    PartiallyOrderedSetFlight<BinaryParticle<eoMinimizingFitness>> flight(instance.getPrecedenceRelation());
    PartiallyOrderedSetFlight<BinaryParticle<eoMaximizingFitness>> flight2(instance.getPrecedenceRelation());

    eoPop<BinaryParticle<eoMaximizingFitness> > pop;
    eoPop<BinaryParticle<eoMinimizingFitness> > pop2;

    eoUniformGenerator < bool >sGen (0, 1);
    eoVelocityInitFixedLength < BinaryParticle<eoMaximizingFitness> > veloRandom (instance.getRequirementsCost().size(), sGen);
    eoVelocityInitFixedLength < BinaryParticle<eoMinimizingFitness> > veloRandom2 (instance.getRequirementsCost().size(), sGen);

    VonNeumannTopology<BinaryParticle<eoMaximizingFitness> > topology(FILAS, COLUMNAS);
    VonNeumannTopology<BinaryParticle<eoMinimizingFitness> > topology2(FILAS, COLUMNAS);

    //FMOPSOBinaryVelocity<eoMaximizingFitness> vel(topology, rng);
    BinaryVelocity<BinaryParticle<eoMaximizingFitness>> vel(topology, rng);
    BinaryVelocity<BinaryParticle<eoMinimizingFitness>> vel2(topology2, rng);

    // Inicializamos a mano las velocidades y las aplicamos con flight
    for(unsigned int i = 0; i < N; i++)
    {
        BinaryParticle<eoMaximizingFitness> part(instance.getRequirementsCost().size());
        BinaryParticle<eoMinimizingFitness> part2(instance.getRequirementsCost().size());
        veloRandom(part);
        veloRandom2(part2);
        flight2(part);
        flight(part2);
        for(unsigned int i = 0; i < part.size(); i++)
        {
            part.bestPositions[i] = part[i];
            part2.bestPositions[i] = part2[i];
        }
        evalFunction2(part);
        evalFunction(part2);
        part.best(part.fitness());
        part2.best(part2.fitness());
        pop.push_back(part);
        pop2.push_back(part2);
    }

    topology.setup(pop);
    topology2.setup(pop2);
    eoGenContinue<BinaryParticle<eoMaximizingFitness> > genContinue(GEN);
    eoGenContinue<BinaryParticle<eoMinimizingFitness> > genContinue2(GEN);
    eoEasyPSO<BinaryParticle<eoMaximizingFitness> > pso1(genContinue, evalFunction2, vel, flight2);
    eoEasyPSO<BinaryParticle<eoMinimizingFitness> > pso2(genContinue2, evalFunction, vel2, flight);

    //std::cout << "Antes del PSO" << std::endl;
    //pop.printOn(std::cout);

    pso1(pop);

    //std::cout << "Después del PSO" << std::endl;
    //pop.printOn(std::cout);
    std::cout << "\n\nMejor partícula encontrada (Profit)" << std::endl;
    std::cout << pop.best_element() << std::endl;

    //std::cout << "Antes del PSO" << std::endl;
    //pop2.printOn(std::cout);

    pso2(pop2);

    //std::cout << "Después del PSO" << std::endl;
    //pop2.printOn(std::cout);
    std::cout << "\n\nMejor partícula encontrada (Cost)" << std::endl;
    std::cout << pop2.best_element() << std::endl;

/*    NRPProblem instance;
    instance.load("nrp1.txt");
    instance.printOn(std::cout);

    PartiallyOrderedSetFlight<BiObjFuzzyNRPFitness> flight(instance.getPrecedenceRelation());
    eoPop<BinaryParticle<BiObjFuzzyNRPFitness> > pop;

    eoUniformGenerator < bool >sGen (0, 1);
    eoVelocityInitFixedLength < BinaryParticle<BiObjFuzzyNRPFitness> > veloRandom (instance.getRequirementsCost().size(), sGen);

    std::vector<eoEvalFunc<BinaryParticle<BiObjFuzzyNRPFitness> >* > eval_funcs;
    //std::vector<BiObjFuzzyNRPFitnessFunction> eval_funcs;
    for(unsigned int j = 0; j < COLUMNAS; j++)
    {
        double cost_exp = 2.0 * (double) j / (double) (COLUMNAS-1);
        //std::cout << cost_exp << std::endl;
        eval_funcs.push_back(new BiObjFuzzyNRPFitnessFunction("nrp1.txt", 2909.0, 787.0, cost_exp, 2.0 - cost_exp));
    }

    FMOPSOTopology<BinaryParticle<BiObjFuzzyNRPFitness> > topology(FILAS, COLUMNAS, eval_funcs);

    FMOPSOBinaryVelocity<BinaryParticle<BiObjFuzzyNRPFitness>> vel(topology, rng);

    // Inicializamos a mano las velocidades y las aplicamos con flight
    for(unsigned int i = 0; i < N; i++)
    {
        BinaryParticle<BiObjFuzzyNRPFitness> part(instance.getRequirementsCost().size());
        veloRandom(part);
        flight(part);
        for(unsigned int i = 0; i < part.size(); i++)
        {
            part.bestPositions[i] = part[i];
        }
        eval_funcs.at(i % COLUMNAS)->operator()(part);
        part.best(part.fitness());
        pop.push_back(part);
    }

    topology.setup(pop);
    eoGenContinue<BinaryParticle<BiObjFuzzyNRPFitness> > genContinue(GEN);
    FMOPSOAlgorithm<BinaryParticle<BiObjFuzzyNRPFitness> > pso1(genContinue, vel, flight, eval_funcs, topology);

    std::cout << "Antes del PSO" << std::endl;
    pop.printOn(std::cout);

    pso1(pop);

    std::cout << "Después del PSO" << std::endl;
    pop.printOn(std::cout);
    std::cout << "\n\nMejor partícula encontrada" << std::endl;
    std::cout << pop.best_element() << std::endl;
    topology.printOn();


    for(int j = COLUMNAS-1; j >= 0; j--)
    {
        delete eval_funcs.at(j);
    }
    eval_funcs.clear();
*/
/*
    NRPProblem instance;
    instance.load("nrp1.txt");
    instance.printOn(std::cout);

    PartiallyOrderedSetFlight<MOBinaryParticle<BiObjNRPObjectiveVector>> flight(instance.getPrecedenceRelation());
    eoPop<MOBinaryParticle<BiObjNRPObjectiveVector> > pop;

    eoUniformGenerator < bool >sGen (0, 1);
    eoVelocityInitFixedLength < MOBinaryParticle<BiObjNRPObjectiveVector> > veloRandom (instance.getRequirementsCost().size(), sGen);

    BiObjNRPMOEval<MOBinaryParticle<BiObjNRPObjectiveVector>> eval("nrp1.txt");

    std::vector<eoEvalFunc<MOBinaryParticle<BiObjNRPObjectiveVector> >* > eval_funcs;
    //std::vector<BiObjFuzzyNRPFitnessFunction> eval_funcs;
    std::vector<double> leftRef(2, 0.0);
    std::vector<double> rightRef;
    rightRef.push_back(2909.0);
    rightRef.push_back(787.0);
    for(unsigned int j = 0; j < COLUMNAS; j++)
    {
        double cost_exp = 2.0 * (double) j / (double) (COLUMNAS-1);

        std::vector<double> expW;
        expW.push_back(2-cost_exp);
        expW.push_back(cost_exp);
        eval_funcs.push_back(new FuzzyFitnessSingleObjectivization<MOBinaryParticle<BiObjNRPObjectiveVector>>(&eval, leftRef, rightRef, expW));
    }

    FMOPSOTopology<MOBinaryParticle<BiObjNRPObjectiveVector>> topology(FILAS, COLUMNAS, eval_funcs);

    FMOPSOBinaryVelocity<MOBinaryParticle<BiObjNRPObjectiveVector>> vel(topology, rng);

    // Inicializamos a mano las velocidades y las aplicamos con flight
    for(unsigned int i = 0; i < N; i++)
    {
        MOBinaryParticle<BiObjNRPObjectiveVector> part(instance.getRequirementsCost().size());
        veloRandom(part);
        flight(part);
        for(unsigned int j = 0; j < part.size(); j++)
        {
            part.bestPositions[j] = part[j];
        }
        eval_funcs.at(i % COLUMNAS)->operator()(part);
        part.best(part.fitness());
        part.setBestObjectiveVectorValue(part.objectiveVector());
        pop.push_back(part);
    }

    topology.setup(pop);
    //eoGenContinue<MOBinaryParticle<BiObjNRPObjectiveVector> > genContinue(GEN);
    eoTimeContinue<MOBinaryParticle<BiObjNRPObjectiveVector>> timeContinue(30);
    FMOPSOAlgorithm<MOBinaryParticle<BiObjNRPObjectiveVector> > pso1(timeContinue, vel, flight, eval_funcs, topology);

    std::cout << "Antes del PSO" << std::endl;
    pop.printOn(std::cout);

    pso1(pop);

    std::cout << "Después del PSO" << std::endl;
    pop.printOn(std::cout);
    std::cout << "\n\nMejor partícula encontrada" << std::endl;
    std::cout << pop.best_element() << std::endl;
    topology.printOn();

    std::cout << "\n\n[";
    std::vector<BiObjNRPObjectiveVector> completeFront;
    std::vector<BiObjNRPObjectiveVector> completeNonBestFront;
    for(MOBinaryParticle<BiObjNRPObjectiveVector> individual: pop)
    {
        std::cout << individual.getBestObjectiveVectorValue() << ";" << std::endl;
        completeFront.push_back(individual.getBestObjectiveVectorValue());
        completeNonBestFront.push_back(individual.objectiveVector());
    }
    std::cout << "];";

    for(int j = COLUMNAS-1; j >= 0; j--)
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
*/

/*    NRPProblem instance;
    instance.load("nrp1.txt");
    instance.printOn(std::cout);

    PartiallyOrderedSetFlight<MOBinaryParticle<BiObjNRPObjectiveVector>> flight(instance.getPrecedenceRelation());

    NRPMutation<moeoBitVector<BiObjNRPObjectiveVector>> mutation(instance.getPrecedenceRelation());
    NRPCrossover<moeoBitVector<BiObjNRPObjectiveVector>> crossover;
    eoPop<moeoBitVector<BiObjNRPObjectiveVector> > pop;

    eoUniformGenerator < bool >sGen (0, 1);
    eoVelocityInitFixedLength < MOBinaryParticle<BiObjNRPObjectiveVector> > veloRandom (instance.getRequirementsCost().size(), sGen);

    BiObjNRPMOEval<moeoBitVector<BiObjNRPObjectiveVector>> eval("nrp1.txt");

    // Inicializamos a mano las velocidades y las aplicamos con flight
    for(unsigned int i = 0; i < N; i++)
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

    eoTimeContinue<moeoBitVector<BiObjNRPObjectiveVector>> timeContinue(30);
    eoSGAGenOp < moeoBitVector<BiObjNRPObjectiveVector> > sgaGenOp(crossover, Pc, mutation, Pm);
    moeoNSGAII<moeoBitVector<BiObjNRPObjectiveVector>> nsgaii(timeContinue, eval, sgaGenOp);

    nsgaii(pop);

    // extract first front of the final population using an moeoArchive (this is the output of nsgaII)
    moeoUnboundedArchive < moeoBitVector<BiObjNRPObjectiveVector> > arch;
    arch(pop);

    // printing of the final archive
    std::cout << "Final Archive" << std::endl;
    arch.sortedPrintOn (std::cout);
    std::cout << std::endl;

    std::vector<BiObjNRPObjectiveVector> completeFront;
    for(moeoBitVector<BiObjNRPObjectiveVector> individual: pop)
    {
        std::cout << individual.objectiveVector() << ";" << std::endl;
        completeFront.push_back(individual.objectiveVector());
    }
    std::cout << "];";

    BiObjNRPObjectiveVector refPoint;
    refPoint[0] = 0.0;
    refPoint[1] = 1.0;

    std::vector<double> leftRef(2, 0.0);
    std::vector<double> rightRef;
    rightRef.push_back(2909.0);
    rightRef.push_back(787.0);

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

    //hypervolume00.setup(completeFront);
    std::cout << "El hipervolumen del frente logrado por el algoritmo es: " << hypervolume00(completeFront) << std::endl;
*/
}
