#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include "data_parser.h"
#include "event.h"


std::vector<Event> DataParser::ReadData()
{
    /*
    Reads csv file with triggers and responses
    Makes a Event class for those values
    Adds Events to vector and returns it.
    */

    std::string line;
    std::string trigger;
    std::string response;
    std::vector<Event> datainfo;

    std::string csvData = "../data/datafile.csv";
    std::string csvDemo = "../data/datademo.csv";
    
    // Open file and 
    std::ifstream datafile(csvDemo);

    if(datafile.is_open())
    {
        // Go through file line by line
        while (std::getline(datafile, line))
        {
            // Grab file line data
            std::stringstream dataline(line);

            // Grab elements in line
            getline(dataline, trigger, ',');
            getline(dataline, response, ',');

            // Make Event class
            // Add Event to vector
            datainfo.push_back(Event(trigger, response));
        }
        datafile.close();
    }

    // Return vector of Events of of csv file
    std::cout << "****************************\tData File\t****************************" << std::endl;
    for(Event event : datainfo)
    {
        std::cout << "Event: " << event.getTrigger() << "\tMessage: " << event.getMessage() << std::endl;
    }
    std::cout << "****************************************************************************" << std::endl;

    return datainfo;

}

std::string DataParser::CurrentTime()
{
    /* Uses chrono library to return the current time sting */
    
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string date_time = std::ctime(&currentTime);
    std::string day, month, date, fullTime, time{""}, year;
    
    std::stringstream stream(date_time);
    stream >> day >> month >> date >> fullTime >> year;

    for(int i = 0; i < 5; i++) { time = time + fullTime[i]; }
    
    return time;

}