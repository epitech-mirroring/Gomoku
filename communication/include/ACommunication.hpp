/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** ACommunication
*/

#ifndef ACOMMUNICATION_HPP_
#define ACOMMUNICATION_HPP_

#include "ICommunication.hpp"
#include "IBoard.hpp"
#include <memory>

class ACommunication : public ICommunication {
    public:
        ACommunication() = default;
        ~ACommunication() = default;

        void analyse() override;
        void start(std::vector<std::string> tab) override;
        void turn(std::vector<std::string> tab) override;
        void Send(std::string message) override
        {
            std::cout << message << std::endl;
        }

        std::string Receive() override
        {
            std::string message;
            std::getline(std::cin, message);
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
            Send("name=\"SomeBrain\"");
        }

        void Uknown() override
        {
            Send("UNKNOWN");
        }

        void dim(int dim)
        {
            _dim = dim;
        }

        int dim()
        {
            return _dim;
        }

    protected:
        int _dim;
        bool _isRunning;
    private:
};

#endif /* !ACOMMUNICATION_HPP_ */
