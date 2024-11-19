/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** tempBoard
*/

#include "tempBoard.hpp"
#include <iostream>

using namespace Gomoku;

tempBoard::tempBoard(int size)
{
    int malSize = (size * size + 4) / 4;
    try
    {
        board = new char[malSize];
    }
    catch(const std::exception& e)
    {
        std::cerr << "ziern" << '\n';
    }

    for (int i = 0; i < malSize; i++)
        board[i] = 0;
    _size = size;
}

tempBoard::~tempBoard()
{
    free(board);
}

CellState tempBoard::getCellState(int x, int y) const
{
    int posInByte = (x + y * _size) % 4;
    char pos = board[(x + y * _size - posInByte) / 4];

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

void tempBoard::setCellState(int x, int y, CellState state)
{
    int posInByte = (x + y * _size) % 4;
    char *pos = &board[(x + y * _size - posInByte) / 4];

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
