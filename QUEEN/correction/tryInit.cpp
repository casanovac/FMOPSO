#include <eo>
#include <queen.h>
#include <queenInit.h>

int main(int argc, char* argv[]){

  //Define a solution (QUEEN) -> 1 line
  QUEEN q;

  //Define a queenInit -> 1 line
  queenInit init(8,1);

  //Init the solution -> 1 line
  init(q);

  //Print the solution -> 1 line
  q.printOn(std::cout);

  
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
