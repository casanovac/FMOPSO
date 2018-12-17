#include <eo>
#include <queen.h>
#include <queenInit.h>
#include <queenCrossover.h>

int main(int argc, char* argv[]){

  //Define two solutions (QUEEN) -> 1 line
  QUEEN q1, q2;

  //define initializer and init the two solutions -> 1 line
  queenInit init(8,1);
  init(q1);
  init(q2);

  //Print the two solutions before the cross -> 1 line
  std::cout << "Solutions before crossing" << std::endl;
  q1.printOn(std::cout);
  std::cout << std::endl;
  q2.printOn(std::cout);
  std::cout << std::endl;
  std::cout << std::endl;

  //Define the crossover
  queenCrossover cross;

  //Mute the solution
  cross(q1, q2);

  //Print again the two solutions -> 1 line
  std::cout << "Solutions after crossing" << std::endl;
  q1.printOn(std::cout);
  std::cout << std::endl;
  q2.printOn(std::cout);

  std::cout << std::endl;
  return EXIT_SUCCESS;
}
