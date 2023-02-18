#include <chrono>
#include <string>
#include "event.h"

Event::Event(std::string trigger, std::string message)
{
    setTrigger(trigger);
    setMessage(message);
}

std::string Event::getTrigger() { return _trigger; }
std::string Event::getMessage() { return _message; }

void Event::setTrigger(std::string trigger) { _trigger = trigger; }
void Event::setMessage(std::string message) { _message = message; }