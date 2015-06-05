#pragma once

#include "SudokuBoard.h"
#include "ISudokuSolver.h"

class SudokuSolverBruteForce : public ISudokuSolver
{
public:
    SudokuSolverBruteForce();
    bool solve(SudokuBoard &p_board) override;

private:
    void resetSolver();
    bool findNextEmptyCell(const SudokuBoard &p_board);

    unsigned short m_col { 0 };
    unsigned short m_row { 0 };
};
