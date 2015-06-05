#pragma once

#pragma once

class SudokuBoard;

class ISudokuSolver
{
public:
    virtual bool solve(SudokuBoard &p_board) = 0;

private:
};

