/*
CLI-based interface for Password Manager
*/

#include "ui.hpp"
#include <iostream>

// Display message when starting Password Manager application
void UI::displayWelcomeMessage() const {
    std::cout << "Welcome to the Password Manager!\n";
    std::cout << "Please enter your master password to continue.\n";
}

// Display the main menu options
void UI::displayMenu() const {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add a new password\n";
    std::cout << "2. View a saved password\n";
    std::cout << "3. Exit\n";
    std::cout << "Please select an option: ";
}

// Display an error message
void UI::displayErrorMessage(const std::string& error) const {
    std::cerr << "\nError: " << error << "\n";
}
