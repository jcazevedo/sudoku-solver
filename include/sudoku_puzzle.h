#ifndef SUDOKU_PUZZLE_H_
#define SUDOKU_PUZZLE_H_

class sudoku_puzzle
{
public:
    const static int MATRIX_SIZE = 9;
    static int       get_square(int row, int column);

private:
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

public:
    sudoku_puzzle();
    virtual ~sudoku_puzzle();

    int  get_value(int row, int column) const;
    void set_value(int row, int column, int value);
    void print() const;
};

#endif

