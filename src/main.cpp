#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include "data_parser.h"
#include "bullybot.h"


int main() {
    std::vector<Event> events = DataParser::ReadData();
    std::string currentTrigger{""};
    std::string token = "5806051021:AAETco0xTYSp9xNvgFuK3jhgD_C2TvB2lYw";
    std::string chatID;
    int counter{1};
    
    std::cout << "Enter chat ID: ";
    std::cin >> chatID;

    Bullybot bot(token, "-" + chatID);
    
    while(true)
    {
        // std::string currentTrigger = DataParser::CurrentTime();
        currentTrigger = "Event" + std::to_string(counter);

        for(Event event : events)
        {
            // if evnet == true
            if(event.getTrigger() == currentTrigger)
            {
                // Call Bullybot
                bot.sendNotification(event.getMessage());
                // std::cout << std::endl;
                std::cout << "\nEvent triggered: " << event.getTrigger() << "\t'" << event.getMessage() << "' message sent to user.\n\n";
            }
        }
        counter++;
        if(counter == 8) { break; }
        
        // wiat 15 min minutes() hours() seconds() milliseconds() microseconds() nanoseconds()
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
        
    return 0;
}