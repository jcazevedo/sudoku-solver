#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_

#include <sudoku_puzzle.h>

class sudoku_solver
{
public:
    virtual bool solve(sudoku_puzzle & puzzle) = 0;
    bool         solved(const sudoku_puzzle & puzzle);
};

#endif

