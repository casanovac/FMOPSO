#include <eo>
#include <queen.h>
#include <queenEval.h>

int main(int argc, char* argv[]){

  //Define two solutions (QUEEN) -> 1 line
  QUEEN q1, q2;

  //init the solutions -> 1 line
  //First permutation [4,2,3,1]
  q1.push_back(4);
  q1.push_back(2);
  q1.push_back(3);
  q1.push_back(1);
  
  //Second permutation [2,4,1,3]
  q2.push_back(2);
  q2.push_back(4);
  q2.push_back(1);
  q2.push_back(3);

  //Define evaluation function
  queenEval eval;

  //Eval the solutions -> 1 line
  eval(q1);
  eval(q2);

  //Print the two evaluated solutions
  q1.printOn(std::cout);
  std::cout << std::endl;
  q2.printOn(std::cout);
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
