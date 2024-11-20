/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Board
*/

#ifndef BOARD_HPP_
#define BOARD_HPP_

namespace Gomoku {
    enum class CellState {
        EMPTY,
        BLACK, // Opponent
        WHITE  // Us
    };

    class Board {
    public:
        explicit Board(int size);

        ~Board();

        [[nodiscard]] CellState getCellState(int x, int y) const;

        void setCellState(int x, int y, CellState state) const;

        [[nodiscard]] char *getBinary() const;

        [[nodiscard]] int getSize() const;

    protected:
        char *_board;
        int _size;
    };
} // namespace Gomoku

#endif /* !BOARD_HPP_ */
