/*
** EPITECH PROJECT, 2024
** GomokuAI
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef DUMBBRAIN_HPP
#define DUMBBRAIN_HPP
#include "ABrain.hpp"

namespace Gomoku {
    class DumbBrain final : public ABrain {
    public:
        explicit DumbBrain(const BoardType *board);

        ~DumbBrain() override = default;

        std::pair<int, int> getNextMove(std::pair<int, int> lastMove) override;

        int scoreBoard(const BoardType *board) override;
    };
}

#endif //DUMBBRAIN_HPP
