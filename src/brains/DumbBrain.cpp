/*
** EPITECH PROJECT, 2024
** GomokuAI
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "DumbBrain.hpp"

using namespace Gomoku;

DumbBrain::DumbBrain(const BoardType *board) : ABrain("DumbBrain", board) {
}

std::pair<int, int> DumbBrain::getNextMove(std::pair<int, int> lastMove) {
    const int dim = this->_board->getSize();
    auto [x, y] = lastMove;

    x++;
    if (x >= dim) {
        x = 0;
        y++;
    }
    if (y >= dim) {
        y = 0;
    }
    return std::make_pair(x, y);
}

int DumbBrain::scoreBoard(const BoardType *board) {
    (void)board;
    return 0;
}
