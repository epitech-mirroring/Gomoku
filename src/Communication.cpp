/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** ACommunication
*/

#include "Communication.hpp"

using namespace Gomoku;

Communication::Communication(ABrain *brain): _brain(brain) {
    _dim = 20;
    _isRunning = true;
}

std::string Communication::cleanMessage(std::string message) {
    if (message.find("\n\r") != std::string::npos) {
        message = message.substr(0, message.find("\n\r"));
    } else if (message.find("\n") != std::string::npos) {
        message = message.substr(0, message.find("\n"));
    } else if (message.find("\r") != std::string::npos) {
        message = message.substr(0, message.find("\r"));
    }
    return message;
}

std::vector<std::string> Communication::split(std::string str,
                                              const std::string &delimiter) {
    std::vector<std::string> parts;
    while (str.find(delimiter) != std::string::npos) {
        parts.push_back(str.substr(0, str.find(delimiter)));
        str = str.substr(str.find(delimiter) + 1);
    }
    parts.push_back(str);
    return parts;
}


void Communication::analyze() {
    while (this->isRunning()) {
        const std::string message = cleanMessage(receive());
        const std::vector<std::string> args = split(message);
        const std::string &command = args[0];

        if (command == "START") {
            start(args);
        } else if (command == "BEGIN" || command == "BOARD") {
            play(static_cast<int>(_dim / 2), static_cast<int>(_dim / 2));
        } else if (command == "TURN") {
            turn(args);
        } else if (command == "END") {
            setIsRunning(false);
        } else if (command == "INFO") {
            continue; // Todo run info logic
        } else if (command == "ABOUT") {
            about();
        } else {
            unknown();
        }
    }
}

void Communication::error(const std::string message) {
    send("ERROR " + message);
}

void Communication::start(const std::vector<std::string> args) {
    if (args.size() == 1) {
        send("OK");
        setDim(20);
    } else if (args.size() == 2) {
        try {
            setDim(std::stoi(args[1]));
        } catch (const std::exception &) {
            error("invalid board size");
            return;
        }
        send("OK");
    }
}

void Communication::turn(const std::vector<std::string> args) {
    if (args.size() != 2) {
        error("invalid turn");
        return;
    }

    const std::vector<std::string> coords = split(args[1], ",");
    if (coords.size() != 2) {
        error("invalid turn");
        return;
    }
    std::pair<int, int> lastMove;
    try {
        lastMove = std::make_pair(std::stoi(coords[0]), std::stoi(coords[1]));
    } catch (const std::exception &) {
        error("invalid turn");
        return;
    }

    auto [x, y] = _brain->getNextMove(lastMove);
    play(x, y);
}

void Communication::send(const std::string message) {
    std::cout << message << std::endl;
}

std::string Communication::receive() {
    std::string message;
    std::getline(std::cin, message);
    return message;
}

void Communication::play(const int x, const int y) {
    send(std::to_string(x) + "," + std::to_string(y));
}

void Communication::about() {
    send("name=\"" + _brain->getName() +
         R"(", version="1.0", author="florian.gaudin & axel.eckenberg")");
}

void Communication::unknown() {
    send("UNKNOWN");
}

int Communication::getDim() const {
    return _dim;
}

bool Communication::isRunning() const {
    return _isRunning;
}

void Communication::setIsRunning(const bool is_running) {
    _isRunning = is_running;
}

void Communication::setDim(const int dim) {
    _dim = dim;
}

void Communication::setBrain(ABrain *brain) {
    _brain = brain;
}

const ABrain *Communication::getBrain() const {
    return _brain;
}
