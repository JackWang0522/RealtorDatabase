#include <iostream>
#include <fstream>

#include "interface.h"
#include "agent.h"
#include "client.h"
#include "clientWithHouse.h"
#include "house.h"
#include "clientWithHouse.h"

using namespace std;

int main() {
    string choice = "a";
    while (choice != "e" && choice != "c") {
        cout << "press [e] to login, enter [c] to create new agent account.\n>>";
        cin >> choice;
    }
    Interface interface;
    interface.loginPage(choice);

    return 0;
}