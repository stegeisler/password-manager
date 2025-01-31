/*
CLI-based interface for Password Manager
*/

#ifndef UI_HPP
#define UI_HPP

#include <string>

class UI {
public:
    // Main UI loop
    void start(); // Starts the user interface and enters the main interaction loop.

    // Display functions
    void displayWelcomeMessage() const;  // Displays a welcome message when the application starts.
    void displayMenu() const;            // Displays the main menu options to the user (e.g., Add Password, View Password, Exit).
    void displayErrorMessage(const std::string& error) const;  // Displays an error message (for invalid input or system issues).

    // User input functions
    std::string getMasterPassword() const;  // Prompts the user for the master password to authenticate.
    std::string getPasswordEntry() const;  // Collects the site, username, and password to be stored.
    void displaySuccessMessage(const std::string& message) const; // Displays a success message after a successful action.

private:
    // Helper functions for formatting UI output
    void clearScreen() const;  // Clears the terminal screen for a cleaner UI (platform-specific).
    void waitForUserInput() const; // Pauses to let the user read messages before continuing.

};

#endif // UI_HPP
