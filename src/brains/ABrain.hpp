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

class ABrain {
public:
    using BoardType = int;

protected:
    std::string _name;
    const BoardType *_board;

    ABrain(std::string name, const BoardType *board);

public:
    virtual ~ABrain() = default;

    [[nodiscard]] std::string getName() const;

    void setBoard(const BoardType *board);

    virtual std::pair<int, int> getNextMove(std::pair<int, int> lastMove) = 0;
};

#endif //ABRAIN_HPP
