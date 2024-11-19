/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** tempBoard
*/

#ifndef TEMPBOARD_HPP_
#define TEMPBOARD_HPP_

#include "IBoard.hpp"

namespace Gomoku
{
    class tempBoard : public IBoard
    {
    public:
        tempBoard(int size);
        ~tempBoard();
        CellState getCellState(int x, int y) const override;
        void setCellState(int x, int y, CellState state) override;

    protected:
        char *board;
        int _size;
    };
    
} // namespace Gomoku


#endif /* !TEMPBOARD_HPP_ */
