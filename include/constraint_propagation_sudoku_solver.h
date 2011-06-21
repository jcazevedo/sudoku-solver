#ifndef CONSTRAINT_PROPAGATION_SUDOKU_SOLVER_H_
#define CONSTRAINT_PROPAGATION_SUDOKU_SOLVER_H_

#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#include <sudoku_solver.h>

using std::vector;
using std::pair;
using std::make_pair;

class constraint_propagation_sudoku_solver : public sudoku_solver
{
private:
    struct puzzle_values
    {
        vector<int> 
        values[sudoku_puzzle::MATRIX_SIZE][sudoku_puzzle::MATRIX_SIZE];
    };

    vector<pair<int, int> > 
        neighbours[sudoku_puzzle::MATRIX_SIZE][sudoku_puzzle::MATRIX_SIZE];
    vector<vector<pair<int, int> > > 
        affected[sudoku_puzzle::MATRIX_SIZE][sudoku_puzzle::MATRIX_SIZE];

    void          set_up_neighbours();
    puzzle_values get_values(const sudoku_puzzle & puzzle);
    bool          set_value(puzzle_values & puzzle, int r, int c, int v);
    bool          remove_from_candidates(puzzle_values & puzzle, int r, int c,
                                         int v);
    bool          solved(const puzzle_values & puzzle);
    bool          solve_aux(puzzle_values & puzzle);

public:
    constraint_propagation_sudoku_solver();
    virtual ~constraint_propagation_sudoku_solver();
    
    bool     solve(sudoku_puzzle & puzzle);
};

#endif
