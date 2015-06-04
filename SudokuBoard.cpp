#include "SudokuBoard.h"

SudokuBoard::SudokuBoard()
{
    for (unsigned short i = 0; i < s_size; ++i)
    {
        m_board.push_back(std::vector<SudokuBoardCell>(s_size));
    }
}

std::vector<SudokuBoardCell> &SudokuBoard::operator[](unsigned short p_column)
{
    return m_board[p_column];
}
