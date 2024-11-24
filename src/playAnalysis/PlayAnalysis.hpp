/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** PlayAnalysis
*/

#ifndef PLAYANALYSIS_HPP_
#define PLAYANALYSIS_HPP_

#include <ctime>
#include <functional>

#include "board/Board.hpp"

namespace Gomoku {
    class PlayAnalysis {
    public:
        PlayAnalysis();

        ~PlayAnalysis();

        int getScore(const Board *board, int x, int y, CellState player,
                     const std::function<int(const Board *, CellState)> &evalFunc,
                     clock_t start = 0,
                     int num = 0) const;
    };
} // namespace Gomoku

#endif /* !PLAYANALYSIS_HPP_ */
