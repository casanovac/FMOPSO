#include <eo>
#include <queen.h>
#include <queenInit.h>
#include <queenMutation.h>
#include <queenCrossover.h>
#include <queenEval.h>
#include <string>

#define N 128
#define GEN 600
#define POP_SIZE 250
#define Pc 0.1
#define Pm 0.1

int main(int argc, char *argv[]) {

    eoParser parser(argc, argv);
    // For each parameter, define Parameter, read it through the parser,
    // and assign the value to the variable

    eoValueParam<uint32_t> seedParam(time(0), "seed", "Random number seed", 'S');
    parser.processParam( seedParam );
    unsigned seed = seedParam.value();

    // description of genotype
    eoValueParam<unsigned int> vecSizeParam(8, "vecSize", "Genotype size",'V');
    parser.processParam( vecSizeParam, "Representation" );
    unsigned vecSize = vecSizeParam.value();

    // parameters for evolution engine
    eoValueParam<unsigned int> popSizeParam(10, "popSize", "Population size",'P');
    parser.processParam( popSizeParam, "Evolution engine" );
    unsigned popSize = popSizeParam.value();

    eoValueParam<unsigned int> tSizeParam(10, "tSize", "Tournament size",'T');
    parser.processParam( tSizeParam, "Evolution Engine" );
    unsigned tSize = tSizeParam.value();

    // init and stop
    eoValueParam<std::string> loadNameParam("", "Load","A save file to restart from",'L');
    parser.processParam( loadNameParam, "Persistence" );
    std::string loadName = loadNameParam.value();

    eoValueParam<unsigned int> maxGenParam(100, "maxGen", "Maximum number of generations",'G');
    parser.processParam( maxGenParam, "Stopping criterion" );
    unsigned maxGen = maxGenParam.value();

    eoValueParam<unsigned int> minGenParam(100, "minGen", "Minimum number of generations",'g');
    parser.processParam( minGenParam, "Stopping criterion" );
    unsigned minGen = minGenParam.value();

    eoValueParam<unsigned int> steadyGenParam(100, "steadyGen", "Number of generations with no improvement",'s');
    parser.processParam( steadyGenParam, "Stopping criterion" );
    unsigned steadyGen = steadyGenParam.value();

    // operators probabilities at the algorithm level
    eoValueParam<double> pCrossParam(0.6, "pCross", "Probability of Crossover", 'C');
    parser.processParam( pCrossParam, "Genetic Operators" );
    double pCross = pCrossParam.value();

    eoValueParam<double> pMutParam(0.1, "pMut", "Probability of Mutation", 'M');
    parser.processParam( pMutParam, "Genetic Operators" );
    double pMut = pMutParam.value();

    // relative rates for crossovers
    eoValueParam<double> onePointRateParam(1, "onePointRate", "Relative rate for one point crossover", '1');
    parser.processParam( onePointRateParam, "Genetic Operators" );
    double onePointRate = onePointRateParam.value();

    eoValueParam<double> twoPointsRateParam(1, "twoPointRate", "Relative rate for two point crossover", '2');
    parser.processParam( twoPointsRateParam, "Genetic Operators" );
    double twoPointsRate = twoPointsRateParam.value();

    eoValueParam<double> uRateParam(2, "uRate", "Relative rate for uniform crossover", 'U');
    parser.processParam( uRateParam, "Genetic Operators" );
    double URate =  uRateParam.value();

    // relative rates and private parameters for mutations;
    eoValueParam<double> pMutPerBitParam(0.01, "pMutPerBit", "Probability of flipping 1 bit in bit-flip mutation", 'b');
    parser.processParam( pMutPerBitParam, "Genetic Operators" );
    double pMutPerBit = pMutPerBitParam.value();

    eoValueParam<double> bitFlipRateParam(0.01, "bitFlipRate", "Relative rate for bit-flip mutation", 'B');
    parser.processParam( bitFlipRateParam, "Genetic Operators" );
    double bitFlipRate =  bitFlipRateParam.value();

    eoValueParam<double> oneBitRateParam(0.01, "oneBitRate", "Relative rate for deterministic bit-flip mutation", 'D');
    parser.processParam( oneBitRateParam, "Genetic Operators" );
    double oneBitRate = oneBitRateParam.value();

    // the name of the "status" file where all actual parameter values will be saved
    std::string str_status = parser.ProgramName() + ".status"; // default value
    eoValueParam<std::string> statusParam(str_status.c_str(), "status","Status file",'S');
    parser.processParam( statusParam, "Persistence" );

    // do the following AFTER ALL PARAMETERS HAVE BEEN PROCESSED
    // i.e. in case you need parameters somewhere else, postpone these
    if (parser.userNeedsHelp())
    {
        parser.printHelp(std::cout);
        exit(1);
    }
    if (statusParam.value() != "")
    {
        std::ofstream os(statusParam.value().c_str());
        os << parser;		// and you can use that file as parameter file
    }

    //Define a QUEEN -> 1 line
    QUEEN queen;

    //Define an initializer -> 1 line
    queenInit initializer(N);

    //Define the evaluation function -> 1 line
    queenEval evalOperator;

    //Define mutation -> 1 line
    queenMutation mutationOperator1;
    eoShiftMutation<QUEEN> mutationOperator2;
    eoPropCombinedMonOp<QUEEN> combinedMutation(mutationOperator1, Pm);
    combinedMutation.add(mutationOperator2, Pm);

    //Define crossover -> 1 line
    queenCrossover crossOperator;

    //Define a generational continuator (put 100 generation for example) -> 1 line
    eoGenContinue<QUEEN> continuator(GEN);

    eoCheckPoint<QUEEN> checkPoint(continuator);

    //Define the transformation object (it contains, the crossover, the crossover rate, the mutation and the mutation rate) -> 1 line
    eoSGATransform<QUEEN> transform(crossOperator, Pc, combinedMutation, Pm);

    //Define a selection method that selects ONE individual by deterministic tournament(put the tournament size at 2 for example) -> 1 line
    eoDetTournamentSelect<QUEEN> detTournamentSelect;

    //Define a "eoSelectPerc" with the tournament with default parameter (allow to select the good size of individuals) -> 1 line
    eoSelectPerc<QUEEN> selectPerc(detTournamentSelect);

    //Define a generational replacement strategy -> 1 line
    eoGenerationalReplacement<QUEEN> generationalReplacement;
    eoWeakElitistReplacement<QUEEN> genReplacement(generationalReplacement);

    //Define a pop of QUEEN -> 1 line
    eoPop<QUEEN> population;

    // Print pop stat in a file every 10 generation
    eoState outState;
    outState.registerObject(population);
    eoCountedStateSaver saver(10, outState, "population");
    checkPoint.add(saver);

    // Print best fitness every generation
    eoBestFitnessStat<QUEEN> bestFitStat;
    checkPoint.add(bestFitStat);

    eoStdoutMonitor monitor;
    monitor.add(bestFitStat);
    checkPoint.add(monitor);

    //Fill the pop with 100 initialized and evaluated QUEEN
    //Use the initializer, the evaluation function and the push_back operator's vector -> A "for" included three insrtuctions
    for (unsigned int i = 0; i < POP_SIZE; i++) {
        QUEEN actualQueen;
        initializer(actualQueen);
        evalOperator(actualQueen);
        population.push_back(actualQueen);
    }

    //Print the pop -> 1 line
    population.printOn(std::cout);

    //HERE you can test whether you succeded in initializing the population by compiling and executing this part of the program.

    //Print end of line (endl)
    std::cout << std::endl;

    /*Define an eoEasyEA with good parameter:
      - continuator
      - evaluation function
      - eoSelectPerc
      - transformation object
      - replacement
     */
    // -> 1 line
    eoEasyEA<QUEEN> ea(checkPoint, evalOperator, selectPerc, transform, genReplacement);

    //run the algorithm on the initialized population -> 1 line
    ea(population);

    std::cout << std::endl;
    population.printOn(std::cout);

    //Print the best element -> 1 line
    std::cout << "Best generation solution: " << std::endl;
    population.best_element().printOn(std::cout);

    //If the fitness value is equal to 0, the best solution is found. Else try again.
    if (population.best_element().fitness() == 0)
        std::cout << "\nBest solution found!" << std::endl;
    else
        std::cout << "Best solution NOT found! Try again..." << std::endl;
    return EXIT_SUCCESS;
}
