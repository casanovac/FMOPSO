#include <eo>
#include <queen.h>
#include <queenInit.h>
#include <queenMutation.h>

int main(int argc, char* argv[]){

  //Define a solution (QUEEN) -> 1 line
  QUEEN queen;

  //define initializer and init the solution -> 2 lines
  queenInit initializer(4);
  initializer(queen);

  //Print the solution -> 1 line

  std::cout << queen << std::endl;

  //Define the mutation -> 1 line
  queenMutation mutation;

  //Mute the solution -> 1 line
  mutation(queen);

  //Print again the solution -> 1 line


  std::cout << queen << std::endl;
  return EXIT_SUCCESS;
}
