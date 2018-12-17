#include <eo>
#include <queen.h>
#include <queenEval.h>

//#define N 4

int main(int argc, char* argv[]){

  //Define two solutions (QUEEN) -> 1 or 2 lines
  QUEEN queen1, queen2;

  //init the solutions
  //First permutation [4,2,3,1] -> 4 lines (use push_back)
  queen1.push_back(4);
  queen1.push_back(2);
  queen1.push_back(3);
  queen1.push_back(1);
  
  //Second permutation [2,4,1,3] -> 4 lines (use push_back)
  queen2.push_back(2);
  queen2.push_back(4);
  queen2.push_back(1);
  queen2.push_back(3);

  //Define evaluation function -> 1 line
  queenEval eval_function;

  //Eval the solutions -> 2 lines
  eval_function(queen1);
  eval_function(queen2);

  //Print the two evaluated solutions
  //here -> 1 line

  std::cout << queen1.fitness() << std::endl;
  //and here -> 1 line

  std::cout << queen2.fitness() << std::endl;

  return EXIT_SUCCESS;
}
