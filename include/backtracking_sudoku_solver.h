#ifndef BACKTRACKING_SUDOKU_SOLVER_H_
#define BACKTRACKING_SUDOKU_SOLVER_H_

#include <set>

#include <sudoku_solver.h>

using std::set;

class backtracking_sudoku_solver : public sudoku_solver
{
private:
    set<int> row_fill[sudoku_puzzle::MATRIX_SIZE];
    set<int> column_fill[sudoku_puzzle::MATRIX_SIZE];
    set<int> square_fill[sudoku_puzzle::MATRIX_SIZE];

    int get_next_row(int r, int c);
    int get_next_column(int r, int c);
    bool solve_aux(sudoku_puzzle & puzzle, int r, int c);

public:
    backtracking_sudoku_solver();
    virtual ~backtracking_sudoku_solver();
    
    bool solve(sudoku_puzzle & puzzle);
};

#endif
