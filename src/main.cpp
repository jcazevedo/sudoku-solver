#include <cstdio>

#include <sudoku_puzzle.h>

int main()
{
    sudoku_puzzle puzzle;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            int v;
            scanf("%d", &v);
            puzzle.set_value(i, j, v);
        }

    puzzle.print();

    return 0;
}
