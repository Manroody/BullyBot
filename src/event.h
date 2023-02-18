#ifndef EVENT_H_
#define EVENT_H_

#include <string>

class Event
{
public:
    Event(std::string trigger, std::string message);
    std::string getTrigger();
    std::string getMessage();

private:
    void setTrigger(std::string trigger);
    void setMessage(std::string message);
    
    std::string _trigger;
    std::string _message;
};

#endif /* EVENT_H_ */