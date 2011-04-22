#include <cstring>
#include <cstdio>

#include <sudoku_puzzle.h>

sudoku_puzzle::sudoku_puzzle()
{
    memset(this->matrix, 0, sizeof(this->matrix));
}

sudoku_puzzle::~sudoku_puzzle()
{
}

int sudoku_puzzle::get_value(int row, int column) const
{
    return this->matrix[row][column];
}

void sudoku_puzzle::set_value(int row, int column, int value)
{
    this->matrix[row][column] = value;
}

void sudoku_puzzle::print() const
{
    for (int i = 0; i < sudoku_puzzle::MATRIX_SIZE; i++)
        printf("+---");
    printf("+\n");
    
    for (int i = 0; i < sudoku_puzzle::MATRIX_SIZE; i++)
    {
        for (int j = 0; j < sudoku_puzzle::MATRIX_SIZE; j++)
            if (matrix[i][j] != 0)
                printf("| %d ", matrix[i][j]);
            else
                printf("|   ");
        printf("|\n");
        
        for (int k = 0; k < sudoku_puzzle::MATRIX_SIZE; k++)
            printf("+---");
        printf("+\n");
    }
}

int sudoku_puzzle::get_square(int row, int column)
{
    if (row < 3 && column < 3)
        return 0;
    else if (row < 3 && column < 6)
        return 1;
    else if (row < 3 && column < 9)
        return 2;
    else if (row < 6 && column < 3)
        return 3;
    else if (row < 6 && column < 6)
        return 4;
    else if (row < 6 && column < 9)
        return 5;
    else if (row < 9 && column < 3)
        return 6;
    else if (row < 9 && column < 6)
        return 7;
    else if (row < 9 && column < 9)
        return 8;

    return -1;
}

