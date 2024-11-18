/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** IBoard
*/

#ifndef IBOARD_HPP_
#define IBOARD_HPP_

namespace Gomoku {

    enum class CellState {
        EMPTY,
        BLACK,
        WHITE
    };

    class IBoard {
        public:
            virtual ~IBoard() = default;

            virtual  CellState getCellState(int x, int y) const = 0;
            virtual void setCellState(int x, int y, CellState state) = 0;

        protected:
        private:
    };
}

#endif /* !IBOARD_HPP_ */
