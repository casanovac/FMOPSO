#include <queenEval.h>

void queenEval::operator()(QUEEN & _queen){
    unsigned int count = 0;
    for(unsigned int i = 0; i < _queen.size(); i++)
    {
        for(unsigned int j = i+1; j < _queen.size(); j++)
        {
            if(_queen[j] == _queen[i] + (j-i) || _queen[j] == _queen[i] + (i-j))
                count++;
        }
    }
    _queen.fitness(count);
}
