/*
 * Handles Business Logic, calls PasswordManager and UI
 */

#include "controller.hpp"

Controller::Controller(UI &ui, PasswordManager &password_manager) : ui(ui), password_manager(password_manager) {
}

// Runs the main loop, displaying the menu and handling user input
void Controller::run() {
    bool running = true;
    ui.displayWelcomeMessage();
    while (running) {
        // Display Menu
        ui.displayMenu();

        // Get user choice
        int choice = ui.getUserMenuChoice();

        // Handle user input
        switch (choice) {
            case 1:
                ui.displayMessage("Adding a new password.");
                // TODO: Handle adding new password
                break;
            case 2:
                ui.displayMessage("View a saved password.");
                // TODO: Handle viewing a saved password
                break;
            case 3:
                ui.displayMessage("Listing all stored passwords.");
                // TODO: Handle listing all saved passwords
                break;
            case 4:
                ui.displayMessage("Saving all passwords to file.");
                // TODO: Handle saving all passwords to file
                break;
            case 5:
                ui.displayMessage("Loading all passwords from file.");
                // TODO: Handle loading all passwords from file
                break;
            case 6:
                ui.displayMessage("Exiting Password Manager.");
                running = false;
                break;
            default:
                ui.displayMessage("Invalid choice. Please try again.");
        }
    }

}
