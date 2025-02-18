/*
CLI-based interface for Password Manager
*/

#include "ui.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>   // For clearing input buffer when reading user input

// Start the UI loop
void UI::start() {
    displayWelcomeMessage();
    std::string masterPassword = getMasterPassword();

    bool running = true;
    int choice = -1;
    while (running) {
        displayMenu();


        // Read user choice from input
        std::cin >> choice;
        // Clear input buffer, prevent unwanted leftover input from interfering with later
        // input requests
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                // TODO: Handle case to add new password
                std::cout << "Adding a new password.\n";
                break;
            case 2:
                // TODO: Handle case to view a saved password
                std::cout << "Viewing a saved password.\n";
                break;
            case 3:
                // TODO: Handle case to list all password entries
                std::cout << "Listing all password entries.\n";
                break;
            case 4:
                // TODO: Handle case to save passwords to file
                std::cout << "Saving passwords to file.\n";
                break;
            case 5:
                // TODO: Handle case to load passwords from file
                std::cout << "Loading passwords from file.\n";
                break;
            case 6:
                // Exit program
                std::cout << "Exiting program.\n";
                running = false;
                break;
            default:
                displayErrorMessage("Invalid action. Please try again.");
        }
    }
}

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
    std::cout << "3. List all stored entries\n";
    std::cout << "4. Save passwords to file\n";
    std::cout << "5. Load passwords from file\n";
    std::cout << "6. Exit\n";
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

// Collects the site, username, password and optional notes and tags to be stored
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

// Displays a success message after a successful action
void UI::displaySuccessMessage(const std::string &message) const {
    std::cout << "\nSuccess: " << message << "\n";
}

// Clear the terminal screen (platform-dependent)
void UI::clearScreen() const {
#if defined(_WIN32)
    // Program is running on Windows
    system("cls");
#else
    // Program is running on Linux/macOS/Unix-like systems
    system("clear");
#endif
}

// Wait for the user to press any key before continuing
void UI::waitForUserInput() const {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
}
