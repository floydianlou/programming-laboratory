//
// Created by alice on 02/07/20.
//

#include <iostream>
#include "Program.h"

void Program::addUser(User *newuser) {
    allUsers.insert(std::make_pair(newuser->getRealName(), newuser));
}



void Program::init() {
    std::string choice;
    std::cout << "\t\t\t\t\t WELCOME TO HAPPYCHAT!" << std::endl << std::endl;
    std::cout << "Press A to continue as '" << currentUser->getRealName() << "'." << std::endl << "Not you? Press B to change account." << std::endl << std::endl;
    std::cin >> choice;
    if(choice == "A") {
        std::cout << "You chose to continue as " << currentUser->getRealName() << "." << std::endl;
        mainMenu();
    } else if (choice == "B") {
        std::cout << "You chose to change account." << std::endl;
        login();
    } else {
        throw std::out_of_range ("No correct choice was made.");
        //TODO manage exception
    }
}

void Program::mainMenu() {
    std::cout << std::endl << "\t\t\t\t\t Hello, " << currentUser->getRealName() << "." << std::endl;
    std::cout << std::endl << "It's currently "; timetime(currentTime); std::cout << "." << std::endl << std::endl;
    choices();

}

void Program::choices() {
    int choice;
    std::cout << "What would you like to do next?" << std::endl;
    std::cout << "(1) See all chats." << std::endl << "(2) Open a chat." << std::endl << "(3) Log out." << std::endl << "(4) Change username." << std::endl;
    std::cin >> choice;
    switch(choice) {
        case 1: {
            std::cout << "Your account contains the following chats: " << std::endl;

            currentUser->printAllChats();
            std::cout << "\t\t\t\t\t-----------------------------" << std::endl;
            choices();
        }
            break;
        case 2: {
            int chatNum;
            currentUser->printAllChats();
            std::cout << "Which chat would you like to open?" << std::endl; std::cin >> chatNum;
            currentUser->openchat(chatNum);
            choices();
        } break;
        case 3: {
            std::cout << "See you next time." << std::endl;
        } break;
        case 4: {
            currentUser->changeUsername();
            choices();
        } break;
        default: {
            std::cout << "No correct choice was made." << std::endl;
            choices();
        } break;

    }
}

void Program::login() {
    std::string username;
    std::cout << "Enter your username: "; std::cin >> username;
    auto itr = allUsers.find(username);
        if(itr != allUsers.end()) {
            currentUser = itr->second;
            std::cout << "Username found. Accessing main menu." << std::endl;
            mainMenu();
        } else {
        std::cout << "Username not found. Creating a new user." << std::endl;
            auto newUser = new User(username);
            addUser(newUser);
            currentUser = newUser;
            std::cout << "New user added. Accessing main menu." << std::endl;
            std::cout << "\t\t\t\t\t-----------------------------" << std::endl;
            mainMenu();

} }

Program::~Program() {

}

