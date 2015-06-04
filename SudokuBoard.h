#pragma once

#include <vector>
#include <boost/optional.hpp>

struct SudokuBoardCell
{
    boost::optional<unsigned short> value;
};

class SudokuBoard
{
public:
    SudokuBoard();
    std::vector<SudokuBoardCell> &operator[](unsigned short p_column);

private:
    static const unsigned short s_size = 9;
    std::vector<std::vector<SudokuBoardCell>> m_board;
};
