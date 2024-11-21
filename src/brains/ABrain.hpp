/*
** EPITECH PROJECT, 2024
** GomokuAI
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef ABRAIN_HPP
#define ABRAIN_HPP
#include <string>
#include "board/Board.hpp"
#include "playAnalysis/PlayAnalysis.hpp"

namespace Gomoku {
    class ABrain {
    public:
        using BoardType = Board;
        using Line = std::tuple<std::pair<int, int>, int, bool, std::pair<bool, bool> >;

    protected:
        std::string _name;
        const BoardType *_board;
        const PlayAnalysis &_playAnalysis;

        ABrain(std::string name, const BoardType *board,
               const PlayAnalysis &playAnalysis);

    public:
        virtual ~ABrain() = default;

        [[nodiscard]] std::string getName() const;

        void setBoard(const BoardType *board);

        virtual std::pair<int, int> getNextMove(std::pair<int, int> lastMove) = 0;

        virtual int scoreBoard(const BoardType *board) const = 0;
    };
}

#endif //ABRAIN_HPP
