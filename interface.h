//
// Created by Jack's Matebook on 6/3/2017.
//

#ifndef FINAL_PROJECT_INTERFACE_H
#define FINAL_PROJECT_INTERFACE_H

#include "agent.h"

class Interface{
public:
    Interface();
    void loginPage(std::string choice);
    void displayWelcomePage();
    void saveAgentToFile();
    bool loadAgentFromFile(std::string username);
    void displayMenuOptions();

private:
    Agent *_agt;
    std::string _fileExtension = ".wzx";
    bool _loggedIn;
};

#endif //FINAL_PROJECT_INTERFACE_H
