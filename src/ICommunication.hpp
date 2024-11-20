/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** ICommunication
*/

#ifndef ICOMMUNICATION_HPP_
#define ICOMMUNICATION_HPP_

#include <iostream>
#include <vector>

namespace Gomoku {
    class ICommunication {
    protected:
        std::string virtual receive() = 0;

        ICommunication() = default;

    public:
        virtual ~ICommunication() = default;

        void virtual send(std::string message) = 0;

        void virtual play(int x, int y) = 0;

        void virtual about() = 0;

        void virtual unknown() = 0;

        void virtual analyze() = 0;

        void virtual start(std::vector<std::string> args) = 0;

        void virtual turn(std::vector<std::string> args) = 0;

        void virtual error(std::string message) = 0;
    };
}

#endif /* !ICOMMUNICATION_HPP_ */
