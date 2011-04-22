#include <cstring>

#include <sudoku_solver.h>

bool sudoku_solver::solved(const sudoku_puzzle & puzzle)
{
    bool row_fill[sudoku_puzzle::MATRIX_SIZE][sudoku_puzzle::MATRIX_SIZE+1];
    bool column_fill[sudoku_puzzle::MATRIX_SIZE][sudoku_puzzle::MATRIX_SIZE+1];
    bool square_fill[sudoku_puzzle::MATRIX_SIZE][sudoku_puzzle::MATRIX_SIZE+1];
    
    memset(row_fill, false, sizeof(row_fill));
    memset(column_fill, false, sizeof(column_fill));
    memset(square_fill, false, sizeof(square_fill));

    for (int i = 0; i < sudoku_puzzle::MATRIX_SIZE; i++)
        for (int j = 0; j < sudoku_puzzle::MATRIX_SIZE; j++)
        {
            int v = puzzle.get_value(i, j);
            int sq = sudoku_puzzle::get_square(i, j);

            if (v == 0)
                return false;

            if (row_fill[i][v])
                return false;
            row_fill[i][v] = true;

            if (column_fill[j][v])
                return false;
            column_fill[j][v] = true;

            if (square_fill[sq][v])
                return false;
            square_fill[sq][v] = true;
        }

    return true;
}
