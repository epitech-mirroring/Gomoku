/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Board
*/

#include "Board.hpp"
#include <iostream>
#include <fstream>

using namespace Gomoku;

Board::Board(const int size) {
    const int malSize = (size * size + 3) / 4;
    _board = new char[malSize];

    for (int i = 0; i < malSize; i++)
        _board[i] = 0;
    _size = size;
    _mallocSize = malSize;
}

Board::~Board() = default;

CellState Board::getCellState(const int x, const int y) const {
    if (x < 0 || x >= _size || y < 0 || y >= _size)
        return OUT_OF_BOUND;
    const int posInByte = (x + y * _size) % 4;
    const char pos = _board[(x + y * _size - posInByte) / 4];

    switch (pos >> posInByte * 2 & 3) {
        case 0:
            return EMPTY;
        case 1:
            return WHITE;
        case 2:
            return BLACK;
        default:
            return OUT_OF_BOUND;
    }
}

void Board::setCellState(const int x, const int y, const CellState state) const {
    int posInByte = (x + y * _size) % 4;
    char *pos = &_board[(x + y * _size - posInByte) / 4];

    posInByte = 4 - posInByte - 1;
    switch (state) {
        case EMPTY:
            *pos &= ~(3 << posInByte * 2);
            break;

        case BLACK:
            *pos &= ~(3 << posInByte * 2);
            *pos |= 2 << (posInByte * 2);
            break;
        case WHITE:
            *pos &= ~(3 << (posInByte * 2));
            *pos |= 1 << (posInByte * 2);
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

void Board::print(const std::string &filename) const {
    std::string filePath = "./" + filename;
    std::ifstream infile(filePath);
    if (infile.good()) {
        infile.close();
        return;
    }
    infile.close();
    std::ofstream file(filePath);

    for (int i = 0; i < _mallocSize; i++) {
        file << _board[i];
    }
    file.close();
}
