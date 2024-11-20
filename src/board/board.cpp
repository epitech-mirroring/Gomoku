/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** board
*/

#include "board.hpp"
#include <iostream>

using namespace Gomoku;

board::board(int size)
{
    int malSize = (size * size + 4) / 4;
    try
    {
        _board = new char[malSize];
    }
    catch(const std::exception& e)
    {
        std::cerr << "ziern" << '\n';
    }

    for (int i = 0; i < malSize; i++)
        _board[i] = 0;
    _size = size;
}

board::~board()
{
    delete[] _board;
}

CellState board::getCellState(int x, int y) const
{
    int posInByte = (x + y * _size) % 4;
    char pos = _board[(x + y * _size - posInByte) / 4];

    switch ((pos >> (posInByte * 2)) & 3)
    {
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

void board::setCellState(int x, int y, CellState state)
{
    int posInByte = (x + y * _size) % 4;
    char *pos = &_board[(x + y * _size - posInByte) / 4];

    switch (state)
    {
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
