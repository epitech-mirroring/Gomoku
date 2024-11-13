/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** ACommunication
*/

#include "ACommunication.hpp"
#include <ctime>

void ACommunication::analyse()
{
    std::string message = "";
    std::string message2 = "";
    std::vector <std::string> tab;
    std::srand(std::time(0));
    while (1) {
        tab = {};
        if (message == "")
            message = Receive();
        if (message.find("\n\r") != std::string::npos) {
            message2 = message.substr(message.find("\n\r") + 1);
            message = message.substr(0, message.find("\n\r"));
        } else {
            message2 = "";
        }
        while (message.find(" ") != std::string::npos) {
            tab.push_back(message.substr(0, message.find(" ")));
            message = message.substr(message.find(" ") + 1);
        }
        message = message.substr(0, message.find("\r\n"));
        tab.push_back(message);
        message = message2;
        if (tab[0].find("START") != std::string::npos) {
            start(tab);
        } else if (tab[0].find("BEGIN") != std::string::npos || tab[0].find("BOARD") != std::string::npos) {
            Play(0, 0);
        } else if (tab[0].find("TURN") != std::string::npos) {
            turn(tab);
        } else if (tab[0].find("END") != std::string::npos) {
            break;
        } else if (tab[0].find("INFO") != std::string::npos) {
            continue;
        } else if (tab[0].find("ABOUT") != std::string::npos) {
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

void ACommunication::turn(std::vector<std::string> tab)
{
    int x = 0;
    int y = 0;
    std::string temp;

    if (tab.size() != 2) {
        Send("ERROR invalid turn");
        return;
    }
    temp = tab[1];
    temp = temp.substr(0, temp.find(","));
    try
    {
        x = std::stoi(temp);
    }
    catch(const std::exception& e)
    {
        Send("ERROR invalid turn");
        return;
    }
    temp = tab[1];
    temp = temp.substr(temp.find(",") + 1);
    try
    {
        y = std::stoi(temp);
    }
    catch(const std::exception& e)
    {
        Send("ERROR invalid turn");
        return;
    }
    if (x >= dim() - 1) {
        x = 0;
        y++;
    } else {
        x++;
    }
    if (y >= dim()) {
        x = 0;
        y = 0;
        return;
    }
    Play(x, y);
}