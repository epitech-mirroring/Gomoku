/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** main
*/

#include <thread>

#include "Communication.hpp"
#include "brains/BetaBrain.hpp"
#include "playAnalysis/PlayAnalysis.hpp"

int main() {
    const Gomoku::PlayAnalysis playAnalysis;
    const Gomoku::Board board(20);
    Gomoku::Communication comm(new Gomoku::BetaBrain(&board, playAnalysis));

    comm.analyze();
    return 0;
}
