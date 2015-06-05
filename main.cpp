#include <iostream>
#include "SudokuSolverBruteForce.h"

using namespace std;

int main()
{
    SudokuBoard l_board;

    l_board =
    {
        {3, 0, 6, 5, 0, 8, 4, 0, 0 },
        {5, 2, 0, 0, 0, 0, 0, 0, 0 },
        {0, 8, 7, 0, 0, 0, 0, 3, 1 },
        {0, 0, 3, 0, 1, 0, 0, 8, 0 },
        {9, 0, 0, 8, 6, 3, 0, 0, 5 },
        {0, 5, 0, 0, 9, 0, 6, 0, 0 },
        {1, 3, 0, 0, 0, 0, 2, 5, 0 },
        {0, 0, 0, 0, 0, 0, 0, 7, 4 },
        {0, 0, 5, 2, 0, 6, 3, 0, 0 }
    };

    std::cout << l_board;

    SudokuSolverBruteForce().solve(l_board);

    std::cout << endl << l_board;


    return 0;
}

