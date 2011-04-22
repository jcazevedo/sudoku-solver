#include <cstdio>

#include <sudoku_puzzle.h>
#include <backtracking_sudoku_solver.h>

int main()
{
    sudoku_puzzle * puzzle = new sudoku_puzzle();
    sudoku_solver * solver = new backtracking_sudoku_solver();

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            int v;
            scanf("%d", &v);
            puzzle->set_value(i, j, v);
        }

    printf("Original puzzle:\n");
    puzzle->print();

    solver->solve(*puzzle);

    printf("\nSolved puzzle:\n");
    puzzle->print();

    return 0;
}
