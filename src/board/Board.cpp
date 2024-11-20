/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Board
*/

#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace Gomoku;

Board::Board(const int size) {
    const int malSize = (size * size + 3) / 4;
    _board = new char[malSize];

    for (int i = 0; i < malSize; i++)
        _board[i] = 0;
    _size = size;
    std::cout << malSize << std::endl;
    _mallocSize = malSize;
    print("board1.txt");
}

Board::~Board() {
}

CellState Board::getCellState(const int x, const int y) const {
    const int posInByte = (x + y * _size) % 4;
    const char pos = _board[(x + y * _size - posInByte) / 4];

    switch ((pos >> (posInByte * 2)) & 3) {
        case 0:
            return CellState::EMPTY;
        case 1:
            return CellState::WHITE;
        case 2:
            return CellState::BLACK;
        default:
            return CellState::EMPTY;
    }
}

void Board::setCellState(const int x, const int y, const CellState state) const {
    int posInByte = (x + y * _size) % 4;
    char *pos = &_board[(x + y * _size - posInByte) / 4];

    posInByte = 4 - posInByte - 1;
    switch (state) {
        case CellState::EMPTY:
            *pos &= ~(3 << (posInByte * 2));
            break;

        case CellState::BLACK:
            *pos &= ~(3 << (posInByte * 2));
            *pos |= 2 << (posInByte * 2);
            break;
        case CellState::WHITE:
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

void Board::print(const std::string filename) const {
    std::string filePath = "./testFiles/" + filename;
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