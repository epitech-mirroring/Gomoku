/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Board
*/

#ifndef BOARD_HPP_
#define BOARD_HPP_


namespace Gomoku
{
    enum class CellState {
        EMPTY,
        BLACK, // Opponent
        WHITE  // Us
    };

    class Board
    {
    public:
        Board(int size);
        ~Board();
        CellState getCellState(int x, int y) const;
        void setCellState(int x, int y, CellState state);

    protected:
        char *_board;
        int _size;
    };
    
} // namespace Gomoku


#endif /* !BOARD_HPP_ */
