/*
Password Manager - Secure Password Storage
    ------------------------------------------
    Author  : Stephan Geisler
    Version : 1.0
    Date    : 2025-01-31
    License : MIT

    Description:
    ------------
    A simple and secure password manager that allows users to:
    - Store, retrieve, and delete encrypted passwords.
    - Authenticate using a master password.
    - Use AES encryption for secure password storage.
    - Store data in an SQLite database.

    Features:
    ---------
    - CLI-based interface (GUI version planned).
    - Uses strong encryption for security.
    - Supports password generation and clipboard management. (planed)

    Dependencies:
    -------------
    - C++17 or later
    - SQLite3 for database management
    - OpenSSL for AES encryption
    - bcrypt for secure password hashing (optional)

    Compilation:
    ------------
    - Using CMake:
      mkdir build && cd build
      cmake .. && make

    - Using g++ (if not using CMake):
      g++ -std=c++17 -o password_manager main.cpp src/*.cpp -lsqlite3 -lssl -lcrypto

    Notes:
    ------
    - Ensure you have SQLite and OpenSSL installed on your system.
    - The database is encrypted but should still be kept in a secure location.
    - Future versions may include a GUI and cloud synchronization.
*/

#include "ui.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    UI ui;
    ui.displayWelcomeMessage();

}
