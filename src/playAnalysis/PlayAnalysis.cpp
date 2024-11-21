/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** PlayAnalysis
*/

#include "PlayAnalysis.hpp"
#include <iostream>
#include <climits>

using namespace Gomoku;

constexpr int LIMIT = 20;
constexpr int TIME_LIMIT = 1000;

PlayAnalysis::PlayAnalysis() = default;

PlayAnalysis::~PlayAnalysis() = default;

int PlayAnalysis::getScore(const Board *board, const int x, const int y,
                           const CellState player,
                           const std::function<int(const Board *)> &evalFunc,
                           const clock_t start,
                           const int num) const {
    // Play the given move on the board
    board->setCellState(x, y, player);

    // Evaluate all the possible responses
    int bestScore = INT_MIN;
    std::vector<std::tuple<std::pair<int, int>, int> > tempMoves;
    for (int i = 0; i < board->getSize(); i++) {
        for (int j = 0; j < board->getSize(); j++) {
            if (board->getCellState(i, j) == EMPTY) {
                // Create a new board with the new move
                board->setCellState(i, j, player == WHITE ? BLACK : WHITE);
                int score = evalFunc(board);
                tempMoves.emplace_back(std::make_pair(i, j), score);
                board->setCellState(i, j, EMPTY);
                if (score > bestScore) {
                    bestScore = score;
                }
            }
        }
    }

    // Cutoff the moves that are not good enough
    constexpr float cutoff = 0.9; // If the score is above 90% of the best score, keep it
    const float minScore = static_cast<float>(bestScore) * cutoff;

    std::vector<std::pair<int, int> > moves;
    for (const auto &[move, score]: tempMoves) {
        if (static_cast<float>(score) >= minScore) {
            moves.push_back(move);
        }
    }

    // Recursively evaluate the moves
    for (const auto &[x, y]: moves) {
        if (num >= LIMIT || clock() - start >= TIME_LIMIT * CLOCKS_PER_SEC) {
            board->setCellState(x, y, EMPTY);
            return bestScore;
        }
        board->setCellState(x, y, player);
        const int score = -getScore(board, x, y,
                                    player == WHITE
                                        ? BLACK
                                        : WHITE, evalFunc, start, num + 1);
        board->setCellState(x, y, EMPTY);
        if (score > bestScore) {
            bestScore = score;
        }
    }

    board->setCellState(x, y, EMPTY);
    std::cout << "Move from " << (player == WHITE ? "WHITE" : "BLACK") <<
            " at " << x << ", " << y << " scored " << bestScore << std::endl;
    return bestScore;
}
