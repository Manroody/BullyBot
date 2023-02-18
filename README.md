# CPPND: Capstone Bullybot
The README describes the project you have built.
Bullybot is a chatbot that sends messages to the user based on events that occur. It uses a csv file with event triggers and the response messages to those events to know when to send the message and what the message will be.

The code has two examples of csv files:
  * datafile.csv has timed events that are meant to be triggered through out the day acting as reminders for the user. The user can update the csv file to add as many triggers as they need for a single day. This can also help with setting new habits.
  * datademo.csv is meant to test the code and all the files are currently set up to run this datademo.csv. Events in this file are just numbered and are meant to be triggered one after the other for testing purposes.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* Telegram - Either phone app store or the web version - (https://web.telegram.org/)

## Basic Build Instructions
1. In Telegram create a “New Group” chat and add @capstone_bullybot
2. Get Chat ID from the web address i.e. (https://web.telegram.org/k/#-<Chat ID Number>)
3. Make a build directory in the top level directory: `mkdir build && cd build`
4. Compile: `cmake .. && make`
5. Run it: `./Bullybot`
6. When prompted enter Chat ID number, enter the 9-digit number from the web url and hit enter

## Files and Class Structure
* bullybot - Class
  * Constructor (public) that takes two strings, a token (private) and chat id (private)
  * Two setters (private) and getters (public) for the token and chat id variables
  * Function called sendNotification (public) that takes a message string as an argument and sends it through Telegram. It does this by using std::system to execute the curl command on the terminal and sends the message to the user for the triggered event.
* data_parser - namespace with three functions
	* ReadData uses std::ifstream to read and parse the csv files in the data folder and returns a vector of event classes. Its set to read the csvDemo file because events in that file occur one after the other. To use the actual csvData file you will need to replace the csvDemo file at line 29 of data_parser.cpp
	* CurrentTime uses the chrono library to to get the current system clock and parses to hh:mm format and returns it as a string
* event - Class
	* Constructor (public) that takes two strings, a trigger (private) and message (private)
  * Two setters (private) and getters (public) for the trigger and message variables
  * This is a simple class that stores information for every event that is in the csv data file
* main
  1. Calls DataParser::ReadData to read the data in the csv file with all the events.
  2. Prompts user to enter chat ID number
  3. Bullbot instance is created with token and user chat id
  4. Continuous while loop is started
  5. For the purpose of using the datademo.csv file line 24 with DataParser::CurrentTime function is committed and currentTrigger is set to “Event<current event number>”
  6. for loop to check if any of the events triggers equal the currentTrigger
    * If so main calls the bot method sendNotification to send triggered events message
  * Note: The counter is for the demo data and will need to be committed out when using DataParser::CurrentTime function for currentTrigger

  * See expected output in data folder

## Criteria
1. The project demonstrates an understanding of C++ functions and control structures.
  * The project is organized with header files, namespaces, and classes. main.cpp is only used to bring everything together.
2. The project reads data from a file and processes the data, or the program writes data to a file.
  * data_parser.cpp reads csv file using std::ifstream. The data is then stored in a vector with event classes. See line 29
3. The project accepts user input and processes the input.
  * User input is needed to determine what chat ID the user is using, the ID is needed to send the Telegram message. See line 18 in main.cpp
4. The project uses Object Oriented Programming techniques.
  * I am using two classes, Bullbot and Event. Bullybot holds the bot information token and chatID and also uses a function to send the user a message after a trigger using that information. Event is a class that holds the trigger and message information that has been parsed from the csv file to know when and what to send the user. See files bullybot.cpp and event.cpp
5. Classes use appropriate access specifiers for class members.
  * All class data members and setter functions are set to private within the respected classes and public getters are used to retrieve that data. See bullybot.cpp and event.cpp
6. Classes encapsulate behavior.
  * All classes use getter and setter functions with the variables of that function set to private. See bullybot.cpp and event.cpp