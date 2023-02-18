#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "bullybot.h"

Bullybot::Bullybot(std::string token, std::string chatID)
{
    setToken(token);
    setChatID(chatID);
}

std::string Bullybot::getToken() { return _token; }
std::string Bullybot::getChatID() { return _chatID; }

void Bullybot::sendNotification(std::string message)
{
    std::string link = _link1 + _token + _link2 + _chatID + _link3 + message + "'";
    std::cout << "Command line input:\t" << link << std::endl;
    std::system(link.c_str());
}

void Bullybot::setToken(std::string token) { _token = token; }
void Bullybot::setChatID(std::string chatID) { _chatID = chatID; }