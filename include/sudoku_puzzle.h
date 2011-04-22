#ifndef SUDOKU_PUZZLE_H_
#define SUDOKU_PUZZLE_H_

class sudoku_puzzle
{
private:
    const static int MATRIX_SIZE = 9;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

public:
    sudoku_puzzle();
    virtual ~sudoku_puzzle();

    int get_value(int row, int column);
    void set_value(int row, int column, int value);
    void print();
};

#endif

