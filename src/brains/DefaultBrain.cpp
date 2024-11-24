/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "DefaultBrain.hpp"

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace Gomoku;

DefaultBrain::DefaultBrain(const BoardType *board, const PlayAnalysis &playAnalysis)
    : ABrain("Default", board, playAnalysis) {
}

std::pair<int, int> DefaultBrain::getNextMove(std::pair<int, int> lastMove) {
    std::vector<std::tuple<std::pair<int, int>, int> > moves;
    _board->setCellState(lastMove.first, lastMove.second, BLACK);
    for (int x = 0; x < this->_board->getSize(); x++) {
        for (int y = 0; y < this->_board->getSize(); y++) {
            if (this->_board->getCellState(x, y) != EMPTY) {
                continue;
            }
            int score = this->_playAnalysis.getScore(this->_board, x, y,
                                                     WHITE,
                                                     [this](const BoardType *board) {
                                                         return this->scoreBoard(board);
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

static ABrain::Line getLine(const ABrain::BoardType *board, const int x, const int y,
                            const int dx,
                            const int dy,
                            const bool isWhite,
                            const int length,
                            const bool isBlockedBefore,
                            const bool isBlockedAfter,
                            const std::pair<int, int> &start,
                            std::vector<std::vector<bool> > &visited) {
    visited[x][y] = true;
    bool newIsBlockedBefore = isBlockedBefore;
    if (x == start.first && y == start.second) {
        if (board->getCellState(x - dx, y - dy) != EMPTY) {
            newIsBlockedBefore = true;
        }
    }
    const int newX = x + dx;
    const int newY = y + dy;
    const CellState cellState = board->getCellState(newX, newY);
    if (cellState == EMPTY) {
        return std::make_tuple(start, length, isWhite,
                               std::make_pair(newIsBlockedBefore, false));
    }
    if (cellState == OUT_OF_BOUND) {
        return std::make_tuple(start, length, isWhite,
                               std::make_pair(newIsBlockedBefore, true));
    }
    if (cellState == BLACK) {
        if (isWhite) {
            return std::make_tuple(start, length, isWhite,
                                   std::make_pair(newIsBlockedBefore, true));
        }
        return getLine(board, newX, newY, dx, dy, isWhite, length + 1, newIsBlockedBefore,
                       isBlockedAfter, start, visited);
    }
    if (!isWhite) {
        return std::make_tuple(start, length, isWhite,
                               std::make_pair(newIsBlockedBefore, true));
    }
    return getLine(board, newX, newY, dx, dy, isWhite, length + 1, newIsBlockedBefore,
                   isBlockedAfter, start, visited);
}

int DefaultBrain::scoreBoard(const BoardType *board) const {
    std::vector<Line> lines;
    std::vector visited(board->getSize(),
                        std::vector<bool>(board->getSize(), false));
    for (int x = 0; x < board->getSize(); x++) {
        for (int y = 0; y < board->getSize(); y++) {
            if (visited[x][y]) {
                continue;
            }
            const CellState cellState = board->getCellState(x, y);
            if (cellState == EMPTY || cellState == OUT_OF_BOUND) {
                continue;
            }
            if (cellState == BLACK) {
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) {
                            continue;
                        }
                        Line line = getLine(board, x, y, dx, dy, false, 1, false, false,
                                            std::make_pair(x, y), visited);
                        lines.push_back(line);
                    }
                }
            } else {
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) {
                            continue;
                        }
                        lines.push_back(getLine(board, x, y, dx, dy, true, 1, false,
                                                false,
                                                std::make_pair(x, y), visited));
                    }
                }
            }
        }
    }


    // If the board is empty, return 0
    if (lines.empty())
        return 0;

    std::vector<Line> blackLines;
    std::vector<Line> whiteLines;
    for (const auto &_line: lines) {
        if (std::get<2>(_line)) {
            whiteLines.push_back(_line);
        } else {
            blackLines.push_back(_line);
        }
    }

    // If black has a 5 length line, return -1000
    for (const auto &[_, length, isBlack, isClosed]: blackLines) {
        if (length == 5) {
            return INT_MIN;
        }
    }

    // If white has a 5 length line, return 1000
    for (const auto &[_, length, isBlack, isClosed]: whiteLines) {
        if (length == 5) {
            return INT_MAX;
        }
    }

    int score = 0;

    // If black has a 4 length line not blocked, remove 100
    for (const auto &[_, length, isBlack, isClosed]: blackLines) {
        const auto &[blockedBefore, blockedAfter] = isClosed;
        if (length == 4) {
            if (!blockedBefore && !blockedAfter) {
                score -= 100;
            }
            if ((blockedBefore && !blockedAfter) || (!blockedBefore && blockedAfter)) {
                score -= 90;
            }
        }
    }

    // If white has a 4 length line not blocked, add 100
    for (const auto &[_, length, isBlack, isClosed]: whiteLines) {
        const auto &[blockedBefore, blockedAfter] = isClosed;
        if (length == 4) {
            if (!blockedBefore && !blockedAfter) {
                score += 100;
            }
            if ((blockedBefore && !blockedAfter) || (!blockedBefore && blockedAfter)) {
                score += 90;
            }
        }
    }

    // For all other line add 10*length*(isBlack ? -1 : 1)
    for (const auto &[_, length, isBlack, isClosed]: lines) {
        score += 10 * length * (isBlack ? -1 : 1);
    }

    return score;
}
