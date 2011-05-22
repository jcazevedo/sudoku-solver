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
    int n = sudoku_puzzle::MATRIX_SIZE;

    for (int i = 0; i < n; i++)
    {
        row_fill[i] = (1<<n)-1;
        column_fill[i] = (1<<n)-1;
        square_fill[i] = (1<<n)-1;
    }
}

void backtracking_sudoku_solver::setup_candidates(const sudoku_puzzle & puzzle)
{
    this->reset_candidates();

    int n = sudoku_puzzle::MATRIX_SIZE;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
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

vector<int> backtracking_sudoku_solver::get_candidates(int r, int c)
{
    int sq = sudoku_puzzle::get_square(r, c);
    int v = row_fill[r]&column_fill[c]&square_fill[sq];
    int n = 1;

    vector<int> values;

    while (v)
    {
        if (v & 1)
            values.push_back(n);
        v >>= 1;
        n++;
    }

    return values;
}

void backtracking_sudoku_solver::add_to_candidates(int r, int c, int v)
{
    int sq = sudoku_puzzle::get_square(r, c);

    row_fill[r] |= (1<<(v-1));
    column_fill[c] |= (1<<(v-1));
    square_fill[sq] |= (1<<(v-1));
}

void backtracking_sudoku_solver::remove_from_candidates(int r, int c, int v)
{
    int n = (1<<sudoku_puzzle::MATRIX_SIZE)-1;
    int sq = sudoku_puzzle::get_square(r, c);

    row_fill[r] &= (n^(1<<(v-1)));
    column_fill[c] &= (n^(1<<(v-1)));
    square_fill[sq] &= (n^(1<<(v-1)));
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
        vector<int> values = this->get_candidates(r, c);
        int n = values.size();

        for (int i = 0; i < n; i++)
        {
            int v = values[i];
            
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
