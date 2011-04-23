SudokuSolver
============

This is a very simple solver of sudoku puzzles.

Usage
-----

You can compile the code by simply issuing the following command:

``make``

After compiled, you can execute it by typing:

``./sudoku-solver``

The program is expecting a puzzle definition from the standard input. A puzzle
definition consists of a 9x9 matrix of space separated integers, where the
integer 0 represents an empty cell. For example:

``0 0 0 0 4 8 0 0 0
0 0 0 0 0 0 0 3 9
0 0 0 7 0 0 6 0 8
3 5 0 0 0 0 4 0 0
0 2 7 4 0 5 3 6 0
0 0 4 0 0 0 0 2 5
5 0 3 0 0 7 0 0 0
1 7 0 0 0 0 0 0 0
0 0 0 3 2 0 0 0 0``

After inserting the puzzle, the program should print the original matrix,
followed by the solved puzzle:

``Original puzzle:
+---+---+---+---+---+---+---+---+---+
|   |   |   |   | 4 | 8 |   |   |   |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   | 3 | 9 |
+---+---+---+---+---+---+---+---+---+
|   |   |   | 7 |   |   | 6 |   | 8 |
+---+---+---+---+---+---+---+---+---+
| 3 | 5 |   |   |   |   | 4 |   |   |
+---+---+---+---+---+---+---+---+---+
|   | 2 | 7 | 4 |   | 5 | 3 | 6 |   |
+---+---+---+---+---+---+---+---+---+
|   |   | 4 |   |   |   |   | 2 | 5 |
+---+---+---+---+---+---+---+---+---+
| 5 |   | 3 |   |   | 7 |   |   |   |
+---+---+---+---+---+---+---+---+---+
| 1 | 7 |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+
|   |   |   | 3 | 2 |   |   |   |   |
+---+---+---+---+---+---+---+---+---+

Solved puzzle:
+---+---+---+---+---+---+---+---+---+
| 9 | 3 | 6 | 5 | 4 | 8 | 1 | 7 | 2 |
+---+---+---+---+---+---+---+---+---+
| 7 | 4 | 8 | 2 | 1 | 6 | 5 | 3 | 9 |
+---+---+---+---+---+---+---+---+---+
| 2 | 1 | 5 | 7 | 3 | 9 | 6 | 4 | 8 |
+---+---+---+---+---+---+---+---+---+
| 3 | 5 | 1 | 8 | 6 | 2 | 4 | 9 | 7 |
+---+---+---+---+---+---+---+---+---+
| 8 | 2 | 7 | 4 | 9 | 5 | 3 | 6 | 1 |
+---+---+---+---+---+---+---+---+---+
| 6 | 9 | 4 | 1 | 7 | 3 | 8 | 2 | 5 |
+---+---+---+---+---+---+---+---+---+
| 5 | 6 | 3 | 9 | 8 | 7 | 2 | 1 | 4 |
+---+---+---+---+---+---+---+---+---+
| 1 | 7 | 2 | 6 | 5 | 4 | 9 | 8 | 3 |
+---+---+---+---+---+---+---+---+---+
| 4 | 8 | 9 | 3 | 2 | 1 | 7 | 5 | 6 |
+---+---+---+---+---+---+---+---+---+``

In case there is no solution to the puzzle, the input matrix is output as the
solved puzzle.

License
-------

(The MIT License)

Copyright (c) 2011 Joao Azevedo <joao.c.azevedo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.