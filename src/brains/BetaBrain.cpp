/*
** EPITECH PROJECT, 2024
** GomokuAI
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "BetaBrain.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace Gomoku;
constexpr int FIVE_IN_A_ROW = 100000; // Win condition
constexpr int FOUR_IN_A_ROW = 1000; // Strong threat
constexpr int OPEN_THREE = 100; // Good offensive/defensive pattern
constexpr int BLOCK_SCORE = 500; // Priority for blocking threats


// Helper to check if a sequence is open-ended
bool isPatternOpen(const Board *board, int x, int y, CellState player, int length) {
    static const std::vector<std::pair<int, int> > directions = {
        {1, 0}, {0, 1}, {1, 1}, {1, -1} // Horizontal, Vertical, Diagonal /
    };

    for (const auto &[dx, dy]: directions) {
        int count = 0;
        bool openStart = false, openEnd = false;

        for (int step = -1; step <= length; ++step) {
            int nx = x + step * dx;
            int ny = y + step * dy;

            if (step < 0) {
                if (board->isValid(nx, ny) && board->getCellState(nx, ny) == EMPTY)
                    openStart = true;
            } else if (step >= length) {
                if (board->isValid(nx, ny) && board->getCellState(nx, ny) == EMPTY)
                    openEnd = true;
            } else {
                if (!board->isValid(nx, ny) || board->getCellState(nx, ny) != player)
                    break;
                count++;
            }
        }
        if (count == length && openStart && openEnd) return true;
    }
    return false;
}


// Helper function to check a line in all directions
bool checkDirection(const Board *board, int x, int y, CellState player, int length) {
    static const std::vector<std::pair<int, int> > directions = {
        {1, 0}, {0, 1}, {1, 1}, {1, -1} // Horizontal, Vertical, Diagonal /
    };

    for (const auto &[dx, dy]: directions) {
        int count = 0;
        for (int step = 0; step < length; ++step) {
            int nx = x + step * dx;
            int ny = y + step * dy;

            if (!board->isValid(nx, ny) || board->getCellState(nx, ny) != player) break;
            count++;
        }
        if (count == length) return true;
    }
    return false;
}


// Check for five in a row (win condition)
bool isFiveInRow(const Board *board, int x, int y, CellState player) {
    return checkDirection(board, x, y, player, 5);
}

// Check for four in a row
bool isFourInRow(const Board *board, int x, int y, CellState player) {
    return checkDirection(board, x, y, player, 4);
}

// Check for open three (three in a row with both ends open)
bool isOpenThree(const Board *board, int x, int y, CellState player) {
    return isPatternOpen(board, x, y, player, 3);
}

// Scoring function for the board
int BetaBrain::scoreBoard(const Board *board, const CellState player) const {
    int score = 0;
    const int size = board->getSize();
    CellState opponent = (player == WHITE) ? BLACK : WHITE;

    // Iterate through the board
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board->getCellState(i, j) == EMPTY) continue;

            // Check for sequences and patterns
            if (isFiveInRow(board, i, j, player)) score += FIVE_IN_A_ROW;
            if (isFiveInRow(board, i, j, opponent)) score -= FIVE_IN_A_ROW;

            if (isFourInRow(board, i, j, player)) score += FOUR_IN_A_ROW;
            if (isFourInRow(board, i, j, opponent)) score -= BLOCK_SCORE;
            // Blocking priority

            if (isOpenThree(board, i, j, player)) score += OPEN_THREE;
            if (isOpenThree(board, i, j, opponent)) score -= OPEN_THREE; // Block open 3s
        }
    }
    return score;
}

BetaBrain::BetaBrain(const BoardType *board, const PlayAnalysis &playAnalysis)
    : ABrain("Beta", board, playAnalysis) {
}

std::pair<int, int> BetaBrain::getNextMove(std::pair<int, int> lastMove) {
    std::vector<std::tuple<std::pair<int, int>, int> > moves;
    _board->setCellState(lastMove.first, lastMove.second, BLACK);
    for (int x = 0; x < this->_board->getSize(); x++) {
        for (int y = 0; y < this->_board->getSize(); y++) {
            if (this->_board->getCellState(x, y) != EMPTY) {
                continue;
            }
            int score = this->_playAnalysis.getScore(this->_board, x, y,
                                                     WHITE,
                                                     [this](const BoardType *board,
                                                 const CellState player) {
                                                         return this->scoreBoard(
                                                             board, player);
                                                     });
            moves.emplace_back(std::make_pair(x, y), score);
        }
    }
    std::sort(moves.begin(), moves.end(),
              [](const auto &a, const auto &b) {
                  return std::get<1>(a) > std::get<1>(b);
              });
    _board->setCellState(std::get<0>(moves[0]).first, std::get<0>(moves[0]).second,
                         WHITE);
    return std::get<0>(moves[0]);
}
