/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** main
*/

#include "PlayAnalysis.hpp"
#include <iostream>
#include <thread>

int evalFunction(Gomoku::Board board) {
    int result = 0;
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            if (board.getCellState(i, j) == Gomoku::CellState::WHITE) {
                result += i + j;
            }
            if (board.getCellState(i, j) == Gomoku::CellState::BLACK) {
                result -= i + j;
            }
        }
    }
    return 0;
}

int main() {
    Gomoku::PlayAnalysis playAnalysis;
    Gomoku::Board board(20);

    board.setCellState(0, 0, Gomoku::CellState::WHITE);
    board.setCellState(1, 1, Gomoku::CellState::BLACK);

    playAnalysis.getScore(board, 0, 0, Gomoku::CellState::WHITE, evalFunction);
    board.print("board.txt");
    return 0;
}
