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

class ICommunication {
    public:
        ICommunication() = default;
        ~ICommunication() = default;

        void virtual Send(std::string message) = 0;
        std::string virtual Receive() = 0;

        void virtual Play(int x, int y) = 0;
        void virtual About() = 0;
        void virtual Uknown() = 0;
        void virtual analyse() = 0;
        void virtual start(std::vector<std::string> tab) = 0;
    protected:
    private:
};

#endif /* !ICOMMUNICATION_HPP_ */
