#ifndef BULLYBOT_H_
#define BULLYBOT_H_

#include <string>

class Bullybot
{
public:
    Bullybot(std::string token, std::string chatID);
    std::string getToken();
    std::string getChatID();
    void sendNotification(std::string message);

private:
    void setToken(std::string token);
    void setChatID(std::string chatID);
    
    std::string _token;
    std::string _chatID;

    // https://api.telegram.org/bot<token>/sendMessage?chat_id=<group chat id>&text=<text message>
    const std::string _link1{"curl 'https://api.telegram.org/bot"};
    const std::string _link2{"/sendMessage?chat_id="};
    const std::string _link3{"&text="};
};

#endif /* BULLYBOT_H_ */