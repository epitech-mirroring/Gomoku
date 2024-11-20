/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** PlayAnalysis
*/

#include "PlayAnalysis.hpp"
#include <iostream>

using namespace Gomoku;

const int TO_GET = 20;
const int TIME_LIMIT = 4;

PlayAnalysis::PlayAnalysis()
{
}

PlayAnalysis::~PlayAnalysis()
{
}

int PlayAnalysis::getScore(Board board, int x, int y, CellState player, std::function<int(Board)> evalFunction, clock_t start)
{
    int score = 0;
    int highestScore = 0;
    int lowestScore = 0;

    if (start == 0)
        start = clock();
    
    board.setCellState(x, y, player);
    score = evalFunction(board);

    if (clock() - start > TIME_LIMIT * CLOCKS_PER_SEC || score > TO_GET || score < -TO_GET)
        return score;
    
    for (int i = 0; i < board.getSize(); i++)
    {
        for (int j = 0; j < board.getSize(); j++)
        {
            if (board.getCellState(i, j) == CellState::EMPTY)
            {
                int newScore = getScore(board, i, j, player == CellState::BLACK ? CellState::WHITE : CellState::BLACK, evalFunction, start);
                if (newScore < lowestScore)
                    lowestScore = newScore;
                if (newScore > highestScore)
                    highestScore = newScore;
                if (player == CellState::WHITE && highestScore > score)
                {
                    score = highestScore;
                }
                else if (player == CellState::BLACK && lowestScore < score)
                {
                    score = lowestScore;
                }
                if ((player == CellState::WHITE && score > TO_GET) || (player == CellState::BLACK && score < -TO_GET) || clock() - start > TIME_LIMIT * CLOCKS_PER_SEC)
                    return score;
            }
        }
    }
    return score;
}
