#include "SudokuSolverBruteForce.h"

SudokuSolverBruteForce::SudokuSolverBruteForce()
{
}

bool SudokuSolverBruteForce::solve(SudokuBoard &p_board)
{
    resetSolver();

    if (not findNextEmptyCell(p_board))
    {
        return true;
    }

    for (int l_num = 1; l_num <= p_board.s_size; ++l_num)
    {
        if (p_board.isNewValueValid(m_row, m_col, l_num))
        {
            p_board[m_row][m_col].value = l_num;

            if (SudokuSolverBruteForce().solve(p_board))
            {
                return true;
            }

            p_board[m_row][m_col].value = boost::none;
        }
    }

    return false;
}

void SudokuSolverBruteForce::resetSolver()
{
    m_row = m_col = 0;
}

bool SudokuSolverBruteForce::findNextEmptyCell(const SudokuBoard &p_board)
{
    int l_row {0};
    int l_col {0};

    for (l_row = 0; l_row < p_board.s_size; ++l_row)
    {
        for (l_col = 0; l_col < p_board.s_size; ++l_col)
        {
            if(not p_board[l_row][l_col].value)
            {
                m_row = l_row;
                m_col = l_col;
                return true;
            }
        }
    }

    m_row = l_row;
    m_col = l_col;

    return false;
}
