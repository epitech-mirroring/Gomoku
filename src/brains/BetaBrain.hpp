/*
** EPITECH PROJECT, 2024
** GomokuAI
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef BETABRAIN_HPP
#define BETABRAIN_HPP
#include "ABrain.hpp"


namespace Gomoku {
    class BetaBrain final : public ABrain {
    public:
        explicit BetaBrain(const BoardType *board, const PlayAnalysis &playAnalysis);

        ~BetaBrain() override = default;

        std::pair<int, int> getNextMove(std::pair<int, int> lastMove) override;

        int scoreBoard(const BoardType *board) const override;
    };
}


#endif //BETABRAIN_HPP
