/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** ACommunication
*/

#include "ACommunication.hpp"

void ACommunication::analyse()
{
    std::string message = "";
    std::string message2 = "";
    std::vector <std::string> tab;
    while (1) {
        if (message == "")
            message = Receive();
            if (message.find("\n") != std::string::npos) {
                message2 = message.substr(message.find("\n") + 1);
                message = message.substr(0, message.find("\n"));
            } else {
                message2 = "";
            }
        while (message.find(" ") != std::string::npos) {
            tab.push_back(message.substr(0, message.find(" ")));
            message = message.substr(message.find(" ") + 1);
        }
        message = message2;
        tab.push_back(message);
        if (tab[0] == "START") {
            start(tab);
        } else if (tab[0] == "BEGIN" || tab[0] == "TURN" || tab[0] == "BOARD") {
            Play(rand() % dim(), rand() % dim());
        } else if (tab[0] == "END") {
            break;
        } else if (tab[0] == "INFO") {
            continue;
        } else if (tab[0] == "ABOUT") {
            About();
        } else {
            Uknown();
        }
    }
}

void ACommunication::start(std::vector<std::string> tab)
{
    if (tab.size() == 1) {
        Send("OK");
        dim(20);
    } else if (tab.size() == 2) {
        try
        {
            dim(std::stoi(tab[1]));
        }
        catch(const std::exception& e)
        {
            Send("ERROR invalid board size");
            return;
        }
        Send("OK");
    }  
}