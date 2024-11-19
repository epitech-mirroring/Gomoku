/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** main
*/

#include "src/Communication.hpp"
#include "src/brains/DumbBrain.hpp"

int main() {
    DumbBrain brain(new DumbBrain::BoardType());
    Communication com(&brain);

    com.analyze();
    return 0;
}
