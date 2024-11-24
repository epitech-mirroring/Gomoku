/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** ACommunication
*/

#ifndef ACOMMUNICATION_HPP_
#define ACOMMUNICATION_HPP_

#include "ICommunication.hpp"
#include "brains/ABrain.hpp"

namespace Gomoku {
    class Communication final : public ICommunication {
        static std::string cleanMessage(std::string message);

        static std::vector<std::string> split(std::string str,
                                              const std::string &delimiter = " ");

    protected:
        int _dim;
        bool _isRunning;
        ABrain *_brain;

        std::string receive() override;

    public:
        explicit Communication(ABrain *brain);

        ~Communication() override = default;

        void analyze() override;

        void start(std::vector<std::string> args) override;

        void turn(std::vector<std::string> args) override;

        void send(std::string message) override;

        void play(int x, int y) override;

        void about() override;

        void unknown() override;

        void error(std::string message) override;

        [[nodiscard]] int getDim() const;

        void setDim(int dim);

        [[nodiscard]] bool isRunning() const;

        void setIsRunning(bool is_running);

        void setBrain(ABrain *brain);

        [[nodiscard]] const ABrain *getBrain() const;
    };
}

#endif /* !ACOMMUNICATION_HPP_ */
