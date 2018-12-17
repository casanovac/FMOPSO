#include <eo>
#include <queen.h>
#include <queenInit.h>
#include <queenCrossover.h>

int main(int argc, char* argv[]){

  //Define two solutions (QUEEN) -> 1 line
  QUEEN queen1, queen2;

  //define initializer and init the two solutions -> 3 lines
  queenInit initializer(4);
  initializer(queen1);
  initializer(queen2);

  //Print the two solutions before the cross
  std::cout << "Solutions before crossing" << std::endl;
  //the first here -> 1 line

  std::cout << queen1 << std::endl;
  //the second here -> 1 line

  std::cout << queen2 << std::endl;
  std::cout << std::endl;

  //Define the crossover -> 1 line
  queenCrossover crossOperator;

  //Cross the solutions -> 1 line
  crossOperator(queen1, queen2);

  //Print again the two solutions
  std::cout << "Solutions after crossing" << std::endl;
  //here -> 1 line

  std::cout << queen1 << std::endl;
  //and here -> 1 line

  std::cout << queen2 << std::endl;
  return EXIT_SUCCESS;
}
