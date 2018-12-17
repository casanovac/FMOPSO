#include <eo>
#include <queen.h>
#include <queenInit.h>
#include <queenMutation.h>
#include <queenCrossover.h>
#include <queenEval.h>

#define N 128
#define GEN 600
#define POP_SIZE 250
#define Pc 0.1
#define Pm 0.1

int main(int argc, char* argv[]){

  //Define a QUEEN -> 1 line
  QUEEN queen;

  //Define an initializer -> 1 line
  queenInit initializer(N);

  //Define the evaluation function -> 1 line
  queenEval evalOperator;

  //Define mutation -> 1 line
  queenMutation mutationOperator;

  //Define crossover -> 1 line
  queenCrossover crossOperator;


  //Define a generational continuator (put 100 generation for example) -> 1 line
  eoGenContinue<QUEEN> continuator(GEN);

  //Define the transformation object (it contains, the crossover, the crossover rate, the mutation and the mutation rate) -> 1 line
  eoSGATransform<QUEEN> transform(crossOperator, Pc, mutationOperator, Pm);

  //Define a selection method that selects ONE individual by deterministic tournament(put the tournament size at 2 for example) -> 1 line 
  eoDetTournamentSelect<QUEEN> detTournamentSelect;

  //Define a "eoSelectPerc" with the tournament with default parameter (allow to select the good size of individuals) -> 1 line
  eoSelectPerc<QUEEN> selectPerc(detTournamentSelect);

  //Define a generational replacement strategy -> 1 line
  eoGenerationalReplacement<QUEEN> genReplacement;

  //Define a pop of QUEEN -> 1 line
  eoPop<QUEEN> population;

  //Fill the pop with 100 initialized and evaluated QUEEN
  //Use the initializer, the evaluation function and the push_back operator's vector -> A "for" included three insrtuctions
  for(unsigned int i = 0; i < POP_SIZE; i++)
  {
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
  eoEasyEA<QUEEN> ea(continuator, evalOperator, selectPerc, transform, genReplacement);

  //run the algorithm on the initialized population -> 1 line
  ea(population);

  std::cout << std::endl;
  population.printOn(std::cout);

  //Print the best element -> 1 line
    std::cout << "Best generation solution: " << std::endl;
  population.best_element().printOn(std::cout);

  //If the fitness value is equal to 0, the best solution is found. Else try again.
  if(population.best_element().fitness() == 0)
      std::cout << "\nBest solution found!" << std::endl;
  else
      std::cout << "Best solution NOT found! Try again..." << std::endl;
  return EXIT_SUCCESS;
}
