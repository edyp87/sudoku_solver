#include "SudokuBoard.h"

SudokuBoard::SudokuBoard()
{
    for (unsigned short i = 0; i < s_size; ++i)
    {
        m_board.push_back(std::vector<SudokuBoardCell>(s_size));
    }
}

std::vector<SudokuBoardCell> &SudokuBoard::operator[](unsigned short p_row)
{
    return m_board[p_row];
}

const std::vector<SudokuBoardCell> &SudokuBoard::operator[](unsigned short p_row) const
{
    return m_board[p_row];
}

bool SudokuBoard::isNewValueValid(unsigned short p_row, unsigned short p_col, unsigned short p_newNumber) const
{
    return isRowValid(p_row, p_newNumber) &&
           isColValid(p_col, p_newNumber) &&
            isBoxValid(p_row - p_row % s_boxSize, p_col - p_col % s_boxSize, p_newNumber);
}

SudokuBoard &SudokuBoard::operator=(const std::initializer_list<std::initializer_list<unsigned short> > p_inputBoard)
{
    for (int i = 0; i < p_inputBoard.size(); ++i)
    {
        for (int j = 0; j < p_inputBoard.begin()[i].size(); ++j)
        {
            if (p_inputBoard.begin()[i].begin()[j] == 0)
            {
                 m_board[i][j].value = boost::none;
            }
            else
            {
                m_board[i][j].value = p_inputBoard.begin()[i].begin()[j];
            }
        }
    }
}

bool SudokuBoard::isRowValid(unsigned short p_row, unsigned short p_newNumber) const
{
    for (unsigned short l_col = 0; l_col < s_size; ++l_col)
    {
        if (m_board[p_row][l_col].value == p_newNumber)
        {
            return false;
        }
    }
    return true;
}

bool SudokuBoard::isColValid(unsigned short p_col, unsigned short p_newNumber) const
{
    for (unsigned short l_row = 0; l_row < s_size; ++l_row)
    {
        if (m_board[l_row][p_col].value == p_newNumber)
        {
            return false;
        }
    }
    return true;
}

bool SudokuBoard::isBoxValid(unsigned short p_boxBeginRow, unsigned short p_boxBeginCol, unsigned short p_newNumber) const
{
    for (unsigned short l_row = 0; l_row < s_boxSize; ++l_row)
    {
        for (unsigned short l_col = 0; l_col < s_boxSize; ++l_col)
        {
            if (m_board[p_boxBeginRow+l_row][p_boxBeginCol+l_col].value == p_newNumber)
            {
                return false;
            }
        }
    }
    return true;
}
