#include <cstring>
#include <cstdio>

#include <backtracking_sudoku_solver.h>

backtracking_sudoku_solver::backtracking_sudoku_solver()
{
}

backtracking_sudoku_solver::~backtracking_sudoku_solver()
{
}

bool backtracking_sudoku_solver::solve(sudoku_puzzle & puzzle)
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

    for (int i = 0; i < sudoku_puzzle::MATRIX_SIZE; i++)
        for (int j = 0; j < sudoku_puzzle::MATRIX_SIZE; j++)
        {
            int v = puzzle.get_value(i, j);
            if (v != 0)
            {
                row_fill[i].erase(v);
                column_fill[j].erase(v);
                square_fill[sudoku_puzzle::get_square(i, j)].erase(v);
            }
        }

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

bool backtracking_sudoku_solver::solve_aux(sudoku_puzzle & puzzle, int r, int c)
{
    if (r >= sudoku_puzzle::MATRIX_SIZE ||
        c >= sudoku_puzzle::MATRIX_SIZE)
        return true;

    int n_r = this->get_next_row(r, c);
    int n_c = this->get_next_column(r, c);

    if (puzzle.get_value(r, c) == 0)
    {
        int sq = sudoku_puzzle::get_square(r, c);

        set<int> values;
        for (set<int>::iterator it = row_fill[r].begin(); 
             it != row_fill[r].end(); 
             it++)
            if (column_fill[c].find(*it) != column_fill[c].end() &&
                square_fill[sq].find(*it) != square_fill[sq].end())
                values.insert(*it);

        for (set<int>::iterator it = values.begin();
             it != values.end();
             it++)
        {
            int v = *it;
            
            puzzle.set_value(r, c, v);
            row_fill[r].erase(v);
            column_fill[c].erase(v);
            square_fill[sq].erase(v);
            
            if (this->solve_aux(puzzle, n_r, n_c))
                return true;

            puzzle.set_value(r, c, 0);
            row_fill[r].insert(v);
            column_fill[c].insert(v);
            square_fill[sq].insert(v);
        }

        return false;
    }

    return this->solve_aux(puzzle, n_r, n_c);
}
