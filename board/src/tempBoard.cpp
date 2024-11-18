/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** tempBoard
*/

#include "tempBoard.hpp"
#include <stdlib.h>

using namespace Gomoku;

tempBoard::tempBoard(int size)
{
    board = (char *)malloc(sizeof(char) * size * size);

    for (int i = 0; i < size * size; i++)
        board[i] = 0;
}

tempBoard::~tempBoard()
{
    free(board);
}

CellState tempBoard::getCellState(int x, int y) const
{
    int posInByte = (x + y * size) % 4;
    char pos = board[(x + y * size - posInByte) / 4];

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
    int posInByte = (x + y * size) % 4;
    char *pos = board + (x + y * size - posInByte) / 4;

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
