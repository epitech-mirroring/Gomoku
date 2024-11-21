/*
** EPITECH PROJECT, 2024
** GomokuAI
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "ABrain.hpp"

#ifndef __APPLE__
#include <utility>
#endif

using namespace Gomoku;

ABrain::ABrain(std::string name, const BoardType *board, const PlayAnalysis &playAnalysis)
    : _name(std::move(name)), _board(board), _playAnalysis(playAnalysis) {
}

std::string ABrain::getName() const {
    return _name;
}

void ABrain::setBoard(const BoardType *board) {
    _board = board;
}
