/*
CLI-based interface for Password Manager
*/

#include "ui.hpp"
#include <iostream>
#include <optional>

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

// Get the master password from the user
std::string UI::getMasterPassword() const {
    std::string masterPassword;
    std::cout << "Enter your master password: ";
    std::cin >> masterPassword;
    return masterPassword;
}

PasswordEntry UI::getPasswordEntry() const {
    std::string site, username, password;
    std::optional<std::string> notes;
    std::vector<std::string> tags;
    std::string input;

    // Get site name
    std::cout << "Enter site name: ";
    std::cin >> site;

    // Get username
    std::cout << "Enter username: ";
    std::cin >> username;

    // Get password
    std::cout << "Enter password: ";
    std::cin >> password;

    // Optional: Get notes (allow empty, so use std::optional)
    std::cout << "Enter notes (press enter to skip): ";
    std::cin.ignore();  // Clear the newline left by the previous std::cin
    std::getline(std::cin, input);
    // If user provided notes, store them in the optional
    if (!input.empty()) {
        notes = input;
    }

    // Optional: Get tags (multiple tags, separated by commas)
    std::cout << "Enter tags (comma separated, press enter to skip): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        std::stringstream sstream(input);
        std::string tag;
        // Split the input by commas and add each tag
        while (std::getline(sstream, tag, ',')) {
            tags.push_back(tag);
        }
    }

    // Return the filled PasswordEntry struct
    return PasswordEntry{site, username, password, notes, tags};
}
