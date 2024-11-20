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
#include "Board.hpp"

namespace Gomoku
{
    class PlayAnalysis {
        public:
            PlayAnalysis();
            ~PlayAnalysis();

            int getScore(Board board, int x, int y, CellState player, std::function<int(Board)> evalFunc, clock_t start = 0);

        protected:
        private:
    };
} // namespace Gomoku

#endif /* !PLAYANALYSIS_HPP_ */
