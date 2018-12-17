#include <eo>
#include <queen.h>
#include <queenInit.h>
#include <queenMutation.h>
#include <queenCrossover.h>
#include <queenEval.h>
#include <moeo>
#include <es/eoRealInitBounded.h>
#include <es/eoRealOp.h>

#define N 8
#define GEN 100
#define POP_SIZE 25
#define Pc 0.6
#define Pm 0.1

// the moeoObjectiveVectorTraits : minimizing 2 objectives
class NQueensBiObjectiveVectorTraits : public moeoObjectiveVectorTraits
{
public:
    static bool minimizing (int i)
    {
        return true;
    }
    static bool maximizing (int i)
    {
        return false;
    }
    static unsigned int nObjectives ()
    {
        return 2;
    }
};


// objective vector of real values
typedef moeoRealObjectiveVector < NQueensBiObjectiveVectorTraits > NQueensBiObjectiveVector;


// multi-objective evolving object for the Sch1 problem
class BiObjQUEEN : public moeoIntVector < NQueensBiObjectiveVector >
{
public:
    BiObjQUEEN() : moeoIntVector < NQueensBiObjectiveVector > (1)
    {}
};

class BiObjQueenEvalQueen
{
public:
    int operator()(BiObjQUEEN & _queen)
    {
        int count = 0;
        for(unsigned int i = 0; i < _queen.size(); i++)
        {
            for(unsigned int j = i+1; j < _queen.size(); j++)
            {
                if(_queen[j] == _queen[i] + (j-i) || _queen[j] == _queen[i] + (i-j))
                    count++;
            }
        }
        return count;
    }
};

class BiObjQueenEvalKnight
{
public:
    int operator()(BiObjQUEEN & _queen)
    {
        int count = 0;
        for(unsigned int i = 0; i < _queen.size(); i++)
        {
            if(_queen[i+1] == _queen[i] + 2 || _queen[i+1] == _queen[i] - 2)
                count++;
            if(_queen[i+2] == _queen[i] + 1 || _queen[i+2] == _queen[i] - 1)
                count++;
        }
        return count;
    }
};

// evaluation of objective functions
class BiObjQUEENEval : public moeoEvalFunc < BiObjQUEEN >
{
public:
    void operator () (BiObjQUEEN & _queen)
    {
        if (_queen.invalidObjectiveVector())
        {
            NQueensBiObjectiveVector objVec;
            queenEval eval;
            objVec[0] = evalAsQueen(_queen);
            objVec[1] = evalAsKnight(_queen);
            _queen.objectiveVector(objVec);
        }
    }
private:
    BiObjQueenEvalQueen evalAsQueen;
    BiObjQueenEvalKnight evalAsKnight;
};

int main(int argc, char* argv[]){

    // objective functions evaluation
    BiObjQUEENEval eval;

    //Define an initializer -> 1 line
    eoInitPermutation<BiObjQUEEN> initializer(N);

    //Define mutation -> 1 line
    eoSwapMutation<BiObjQUEEN> mutationOperator;

    //Define crossover -> 1 line
    eoOrderXover<BiObjQUEEN> crossOperator;


    //Define a generational continuator (put 100 generation for example) -> 1 line
    eoGenContinue<QUEEN> continuator(GEN);

    eoPop < BiObjQUEEN > pop (POP_SIZE, initializer);
    for(eoPop< BiObjQUEEN >::iterator it = pop.begin(); it != pop.end(); it++)
    {
        eval(*it);
    }

    pop.printOn(std::cout);

    // build NSGA-II
    moeoNSGAII < BiObjQUEEN > nsgaII (GEN, eval, crossOperator, Pc, mutationOperator, Pm);

    // run the algo
    nsgaII (pop);

    // extract first front of the final population using an moeoArchive (this is the output of nsgaII)
    moeoUnboundedArchive < BiObjQUEEN > arch;
    arch(pop);

    // printing of the final archive
    std::cout << "Final Archive" << std::endl;
    arch.sortedPrintOn (std::cout);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
