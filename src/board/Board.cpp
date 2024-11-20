/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Board
*/

#include "Board.hpp"
#include <iostream>

using namespace Gomoku;

Board::Board(const int size) {
    const int malSize = (size * size + 4) / 4;
    _board = new char[malSize];

    for (int i = 0; i < malSize; i++)
        _board[i] = 0;
    _size = size;
}

Board::~Board() {
    delete[] _board;
}

CellState Board::getCellState(const int x, const int y) const {
    const int posInByte = (x + y * _size) % 4;
    const char pos = _board[(x + y * _size - posInByte) / 4];

    switch ((pos >> (posInByte * 2)) & 3) {
        case 0:
            return CellState::EMPTY;
        case 1:
            return CellState::BLACK;
        case 2:
            return CellState::WHITE;
        default:
            return CellState::EMPTY;
    }
}

void Board::setCellState(const int x, const int y, const CellState state) const {
    int posInByte = (x + y * _size) % 4;
    char *pos = &_board[(x + y * _size - posInByte) / 4];

    switch (state) {
        case CellState::EMPTY:
            *pos &= ~(3 << (posInByte * 2));
            break;

        case CellState::BLACK:
            *pos &= ~(3 << (posInByte * 2));
            *pos |= 1 << (posInByte * 2);
            break;
        case CellState::WHITE:
            *pos &= ~(3 << (posInByte * 2));
            *pos |= 2 << (posInByte * 2);
            break;
        default:
            break;
    }
}

int Board::getSize() const {
    return _size;
}

char *Board::getBinary() const {
    return _board;
}
