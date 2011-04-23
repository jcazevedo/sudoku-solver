#include <cstring>
#include <cstdio>

#include <backtracking_sudoku_solver.h>

backtracking_sudoku_solver::backtracking_sudoku_solver()
{
}

backtracking_sudoku_solver::~backtracking_sudoku_solver()
{
}

void backtracking_sudoku_solver::reset_candidates()
{
    for (int i = 0; i < sudoku_puzzle::MATRIX_SIZE; i++)
    {
        row_fill[i].clear();
        column_fill[i].clear();
        square_fill[i].clear();

        for (int j = 1; j <= 9; j++)
        {
            row_fill[i].insert(j);
            column_fill[i].insert(j);
            square_fill[i].insert(j);
        }
    }
}

void backtracking_sudoku_solver::setup_candidates(const sudoku_puzzle & puzzle)
{
    this->reset_candidates();
    for (int i = 0; i < sudoku_puzzle::MATRIX_SIZE; i++)
        for (int j = 0; j < sudoku_puzzle::MATRIX_SIZE; j++)
        {
            int v = puzzle.get_value(i, j);
            if (v != 0)
                this->remove_from_candidates(i, j, v);
        }
}

bool backtracking_sudoku_solver::solve(sudoku_puzzle & puzzle)
{
    this->setup_candidates(puzzle);
    return this->solve_aux(puzzle, 0, 0);
}

int backtracking_sudoku_solver::get_next_row(int r, int c)
{
    if (c+1 >= sudoku_puzzle::MATRIX_SIZE)
        return r+1;
    return r;
}

int backtracking_sudoku_solver::get_next_column(int r, int c)
{
    if (c+1 >= sudoku_puzzle::MATRIX_SIZE)
        return 0;
    return c+1;
}

set<int> backtracking_sudoku_solver::get_candidates(int r, int c)
{
    int sq = sudoku_puzzle::get_square(r, c);

    set<int> values;
    for (set<int>::iterator it = row_fill[r].begin(); 
         it != row_fill[r].end(); 
         it++)
        if (column_fill[c].find(*it) != column_fill[c].end() &&
            square_fill[sq].find(*it) != square_fill[sq].end())
            values.insert(*it);

    return values;
}

void backtracking_sudoku_solver::add_to_candidates(int r, int c, int v)
{
    int sq = sudoku_puzzle::get_square(r, c);
    row_fill[r].insert(v);
    column_fill[c].insert(v);
    square_fill[sq].insert(v);
}

void backtracking_sudoku_solver::remove_from_candidates(int r, int c, int v)
{
    int sq = sudoku_puzzle::get_square(r, c);
    row_fill[r].erase(v);
    column_fill[c].erase(v);
    square_fill[sq].erase(v);
}

bool backtracking_sudoku_solver::solve_aux(sudoku_puzzle & puzzle, int r, int c)
{
    if (r >= sudoku_puzzle::MATRIX_SIZE ||
        c >= sudoku_puzzle::MATRIX_SIZE)
        return this->solved(puzzle);

    int n_r = this->get_next_row(r, c);
    int n_c = this->get_next_column(r, c);

    if (puzzle.get_value(r, c) == 0)
    {
        set<int> values = this->get_candidates(r, c);

        for (set<int>::iterator it = values.begin();
             it != values.end();
             it++)
        {
            int v = *it;
            
            puzzle.set_value(r, c, v);
            this->remove_from_candidates(r, c, v);
            
            if (this->solve_aux(puzzle, n_r, n_c))
                return true;

            puzzle.set_value(r, c, 0);
            this->add_to_candidates(r, c, v);
        }

        return false;
    }

    return this->solve_aux(puzzle, n_r, n_c);
}
