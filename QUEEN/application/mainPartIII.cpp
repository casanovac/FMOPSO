#include <eo>
#include <queen.h>
#include <queenInit.h>
#include <queenMutation.h>
#include <queenCrossover.h>
#include <queenEval.h>
#include <string>
#include <problems/permutation/moSwapNeighbor.h>
#include <problems/permutation/moSwapNeighborhood.h>
#include <eval/moFullEvalByModif.h>
#include <algo/moSimpleHC.h>

#define N 128
#define GEN 600
#define POP_SIZE 250
#define Pc 0.1
#define Pm 0.1

int main(int argc, char *argv[]) {

    //Define a QUEEN -> 1 line
    QUEEN queen;

    //Define an initializer -> 1 line
    queenInit initializer(N);

    initializer(queen);

    //Define the evaluation function -> 1 line
    queenEval evalOperator;

    evalOperator(queen);

    std::cout << "Initial Solution:" << std::endl;
    std::cout << queen << std::endl << std::endl;

    //moSwapNeighbor<QUEEN> swapNeighbour;
    moSwapNeighborhood<QUEEN> swapNeighbourhood;

    //swapNeighbourhood.init(queen, swapNeighbour);
    moFullEvalByModif< moSwapNeighbor<QUEEN> > swapEval(evalOperator);

    //swapEval(queen, swapNeighbour);

    //swapNeighbour.print();

    /*while (swapNeighbourhood.cont(queen)) {
        swapNeighbourhood.next(queen, swapNeighbour);
        swapEval(queen,swapNeighbour);
        swapNeighbour.print();
    }*/

    moSimpleHC< moSwapNeighbor<QUEEN> > hc(swapNeighbourhood, evalOperator, swapEval);

    hc(queen);

    // Output: the final solution
    std::cout << "final:   " << queen << std::endl ;

    return EXIT_SUCCESS;
}
