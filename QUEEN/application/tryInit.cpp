#include <eo>
#include <queen.h>
#include <queenInit.h>

#define N 8

int main(int argc, char* argv[]){

    //Define a solution (QUEEN) -> 1 line
    QUEEN queen;

    //Define a queenInit -> 1 line
    queenInit initializer(N);

    //Init the solution -> 1 line
	initializer(queen);

    //Print the solution -> 1 line


  
  std::cout << queen << std::endl;
  return EXIT_SUCCESS;
}
