/*
 * Handles Business Logic, calls PasswordManager and UI
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "ui.hpp"
#include "password_manager.hpp"

class Controller {
public:
    Controller(UI& ui, PasswordManager& password_manager);
    void run();     // Runs the main loop, displaying the menu and handling user input

private:
    UI& ui;
    PasswordManager& password_manager;
};


#endif //CONTROLLER_HPP
