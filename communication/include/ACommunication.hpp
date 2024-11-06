/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** ACommunication
*/

#ifndef ACOMMUNICATION_HPP_
#define ACOMMUNICATION_HPP_

#include "ICommunication.hpp"

class ACommunication : public ICommunication {
    public:
        ACommunication() = default;
        ~ACommunication() = default;

        void Send(std::string message) override
        {
            std::cout << message << "\n" << std::endl;
        }
        std::string Receive() override
        {
            std::string message;
            std::cin >> message;
            return message;
        }

        void Play(int x, int y) override
        {
            std::string message;
            message = std::to_string(x);
            message += ", ";
            message += std::to_string(y);
            Send(message);
        }
        void About() override
        {
            Send("name=\"pbrain-gomoku-ai\", version=\"0.1\", author=\"Flo and Axel\", country=\"FR\"");
        }
        void Uknown() override
        {
            Send("UNKNOWN");
        }
    protected:
    private:
};

#endif /* !ACOMMUNICATION_HPP_ */
