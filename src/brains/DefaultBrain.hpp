/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef DEFAULTBRAIN_HPP
#define DEFAULTBRAIN_HPP
#include "ABrain.hpp"

namespace Gomoku {
    class DefaultBrain final : public ABrain {
    public:
        explicit DefaultBrain(const BoardType *board, const PlayAnalysis &playAnalysis);

        ~DefaultBrain() override = default;

        std::pair<int, int> getNextMove(std::pair<int, int> lastMove) override;

        int scoreBoard(const BoardType *board) const override;
    };
}

#endif //DEFAULTBRAIN_HPP
