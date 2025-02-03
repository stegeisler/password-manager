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