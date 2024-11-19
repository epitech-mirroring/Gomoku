/*
** EPITECH PROJECT, 2024
** GomokuAI
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "DumbBrain.hpp"

DumbBrain::DumbBrain(const BoardType *board) : ABrain("DumbBrain", board) {
}

std::pair<int, int> DumbBrain::getNextMove(std::pair<int, int> lastMove) {
    // TODO Get board dim
    const int dim = 20;
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
