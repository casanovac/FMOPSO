#include <eo>
#include <queen.h>
#include <queenInit.h>
#include <queenMutation.h>

int main(int argc, char* argv[]){

  //Define a solution (QUEEN) -> 1 line
  QUEEN q;

  //define initializer and init the solution -> 1 line
  queenInit init(8,1);
  init(q);

  //Print the solution -> 1 line
  q.printOn(std::cout);
  std::cout << std::endl;

  //Define the mutation
  queenMutation mut;

  //Mute the solution
  mut(q);

  //Print again the solution -> 1 line
  q.printOn(std::cout);

  std::cout << std::endl;
  return EXIT_SUCCESS;
}
