//
// Created by Jack's Matebook on 6/3/2017.
//

#include <iostream>
#include <fstream>
#include <string>
#include "interface.h"
#include "agent.h"


using namespace std;

// default constructor
Interface::Interface() {
    _loggedIn = false;
}

// Load login information, ask user to log in.
void Interface::loginPage(string choice) {
    string username = "";
    string password = "";

    if(choice=="c"){
        while(username.size() < 6) {
            cout << "Enter the username you want to use.\n>>";
            cin >> username;
            if (username.size() < 6){cout << "Username must be at least 6 characters long.\n";}
        }
        while(password.size() < 8) {
            cout << "Enter the password you want to use.\n>>";
            cin >> password;
            if(password.size() < 8){cout << "Password must be at least 8 characters.\n";}
        }
        string confirmPassword = "0";
        while (true) {
            cout << "Enter the password again to confirm.\n>>";
            cin >> confirmPassword;
            if(password == confirmPassword){ break;}
            else{cout << "Password does not match.\n";}
        }
        _agt = new Agent(username, password);
        cout << _agt->getUserName() << endl;
        saveAgentToFile();
        displayWelcomePage();
    }
    else{
        cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;
        if (loadAgentFromFile(username)){
            while(!_agt->login(username, password)){
                cout << "Wrong password, enter again.\n"
                        "Enter password : ";
                cin >> password;
            }
            displayWelcomePage();
        }
        else
        {
            cout << "User does not exist!\n";
            loginPage(choice);
        }
    }
}

// Welcome the user and output the name so the user know it is the right account
void Interface::displayWelcomePage() {
    string enter;
    int choice = -1;
    if(!_loggedIn) {
        cout << "\n==============================\n"
                        "Welcome   " + _agt->getName() + "\n"
                        "==============================\n";
        _loggedIn = true;
    }
    displayMenuOptions();
}

// Save the current Agent object to file
void Interface::saveAgentToFile() {
    ofstream outFile;
    outFile.open(_agt->getUserName() + _fileExtension, ios::out | ios::app | ios::binary);
    outFile.write((char *)(_agt), sizeof(_agt));
    cout << "==saved==";
}

// load Agent object from file
bool Interface::loadAgentFromFile(string username) {
    ifstream inFile;
    inFile.open(username + _fileExtension, ios::in | ios::app | ios::binary);
    if (inFile){
        inFile.read((char *)(_agt), sizeof(_agt));
        return true;
    } else{
        return false;
    }
}

// Display menu after user logged in
void Interface::displayMenuOptions(){
    int choice = -1;

    // ask user for choice
    cout << "You have " << _agt->getClientCount() << " clients, " << _agt->getHouseCount() << " houses.\n";
    while((choice < 0 || choice > 9) && choice != 911) {
        cout << "\n============Menu============\n"
                "[1] Find client by name\n"
                "[2] Find client by phone number\n"
                "[3] Find house by address\n"
                "[4] Find house by MLS number\n"
                "[5] Display all clients\n"
                "[6] Display all houses\n"
                "[7] Add a client\n"
                "[8] Add a house\n"
                "[9] Change password\n"
                "[0] Change name\n"
                "[911] Exit\n"
                ">>";
        cin >> choice;
    }

    // operation based on user choice
    switch (choice){
        case 911:{
            break;
        }
        case 1:{
            string name;
            cout << "Enter client's name\n>>";
            cin >> name;
            _agt->findClientByNameAndPrint(name);
            break;
        }
        case 2:{
            string phoneNum;
            cout << "Enter client's name\n>>";
            cin >> phoneNum;
            _agt->findClientByPhoneAndPrint(phoneNum);
            break;
        }
        case 3:{
            string houseAddress;
            cout << "Enter house's address\n>>";
            cin >> houseAddress;
            _agt->findHouseByAddressAndPrint(houseAddress);
            break;
        }
        case 4:{
            string MLS;
            cout << "Enter house's MLS number\n>>";
            cin >> MLS;
            _agt->findHouseByMLSAndPrint(MLS);
            break;
        }
        case 5:{
            _agt->displayAllClients();
            break;
        }
        case 6:{
            _agt->displayAllHouses();
            break;
        }
        case 7:{
            _agt->addNewClient();
            saveAgentToFile();
            break;
        }
        case 8:{
            _agt->addNewHouse();
            saveAgentToFile();
            break;
        }
        case 9:{
            _agt->changePassword();
            saveAgentToFile();
            break;
        }
        case 0:{
            _agt->changeName();
            saveAgentToFile();
            break;
        }
        default:{
            cout << "Selection invalid\n";
            break;
        }
    }
    if(choice != 911) {
        displayWelcomePage();
    }
}