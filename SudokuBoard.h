#pragma once

#include <vector>
#include <boost/optional.hpp>
#include <iostream>
#include <initializer_list>

struct SudokuBoardCell
{
    boost::optional<unsigned short> value;
};

class SudokuBoard
{
public:
    SudokuBoard();
    std::vector<SudokuBoardCell> &operator[](unsigned short p_row);
    const std::vector<SudokuBoardCell> &operator[](unsigned short p_row) const;
    bool isNewValueValid(unsigned short p_row, unsigned short p_col, unsigned short p_newNumber) const;

    SudokuBoard & operator=(const std::initializer_list<std::initializer_list<unsigned short>> p_inputBoard);

    static const unsigned short s_size = 9;
    static const unsigned short s_boxSize = 3;
private:
    bool isRowValid(unsigned short p_row, unsigned short p_newNumber) const;
    bool isColValid(unsigned short p_col, unsigned short p_newNumber) const;
    bool isBoxValid(unsigned short p_boxBeginRow, unsigned short p_boxBeginCol, unsigned short p_newNumber) const;
    std::vector<std::vector<SudokuBoardCell>> m_board;
};

inline std::ostream & operator<<(std::ostream &p_stream, const SudokuBoard &p_board)
{
    for (unsigned short i = 0; i < p_board.s_size; ++i)
    {
        for (unsigned short j = 0; j < p_board.s_size; ++j)
        {
            if (p_board[i][j].value)
            {
                p_stream << p_board[i][j].value.get() << " ";
            }
            else
            {
                p_stream << "_ ";
            }
        }
        p_stream << std::endl;
    }
    return p_stream;
}
