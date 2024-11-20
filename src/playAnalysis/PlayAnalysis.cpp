/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** PlayAnalysis
*/

#include "PlayAnalysis.hpp"
#include <iostream>
#include <limits.h>

using namespace Gomoku;

const int LIMIT = 20;
const int TIME_LIMIT = 4;

PlayAnalysis::PlayAnalysis()
{
}

PlayAnalysis::~PlayAnalysis()
{
}

int PlayAnalysis::getScore(Board board, int x, int y, CellState player, std::function<int(Board)> evalFunction, clock_t start, int num)
{
    int score = 0;
    int highestScore = 0;
    int lowestScore = 0;
    std::string filename = "x" + std::to_string(x) + "y" + std::to_string(y) + ".txt";

    board.print(filename);
    if (start == 0)
        start = clock();
    
    board.setCellState(x, y, player);
    score = evalFunction(board);

    if (clock() - start > TIME_LIMIT * CLOCKS_PER_SEC || num > LIMIT || score >= INT_MAX || score <= INT_MIN)
        return score;
    for (int i = 0; i < board.getSize(); i++)
    {
        for (int j = 0; j < board.getSize(); j++)
        {
            if (board.getCellState(i, j) == CellState::EMPTY)
            {
                if (num == 0)
                    std::cout << "x: " << i << " y: " << j << std::endl;
                int newScore = getScore(board, i, j, player == CellState::BLACK ? CellState::WHITE : CellState::BLACK, evalFunction, start, num + 1);
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
                if (score >= INT_MAX || score <= INT_MIN || clock() - start > TIME_LIMIT * CLOCKS_PER_SEC)
                    return score;
            }
        }
    }
    return score;
}
