/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Board
*/

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <string>

namespace Gomoku {
    enum CellState {
        EMPTY,
        BLACK, // Opponent
        WHITE, // Us
        OUT_OF_BOUND
    };

    class Board {
    public:
        explicit Board(int size);

        ~Board();

        [[nodiscard]] CellState getCellState(int x, int y) const;

        void setCellState(int x, int y, CellState state) const;

        [[nodiscard]] char *getBinary() const;

        [[nodiscard]] int getSize() const;

        void print(const std::string &filename) const;

        bool isValid(int x, int y) const;

    protected:
        char *_board;
        int _size;
        int _mallocSize;
    };
} // namespace Gomoku

#endif /* !BOARD_HPP_ */
