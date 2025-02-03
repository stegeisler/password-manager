#include "ui.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

// Test UI welcome message function
TEST(UITest, WelcomeMessage) {
    UI ui;
    const std::string expected =
        "Welcome to the Password Manager!\n"
        "Please enter your master password to continue.\n";

    // Redirect cout to output
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Capture the printed output
    ui.displayWelcomeMessage();

    // Restore original cout
    std::cout.rdbuf(oldCout);

    // Compare captured output
    EXPECT_EQ(output.str(), expected);
}

// Test UI display menu function
TEST(UITest, DisplayMenu) {
    UI ui;

    // Expected menu output
    const std::string expected =
        "\nMenu:\n"
        "1. Add a new password\n"
        "2. View a saved password\n"
        "3. Exit\n"
        "Please select an option: ";

    // Redirect std::cout to a string stream
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Call function to capture output
    ui.displayMenu();

    // Restore original std::cout
    std::cout.rdbuf(oldCout);

    // Compare captured output with expected output
    EXPECT_EQ(output.str(), expected);
}

// Test UI display error message function
TEST(UITest, DisplayErrorMessage) {
    UI ui;
    const std::string expected =
        "\nError: Some error occurred.\n";

    // Redirect cerr to output
    std::ostringstream errorOutput;
    std::streambuf* oldCerr = std::cerr.rdbuf(errorOutput.rdbuf());

    // Capture the printed output
    const std::string errorMessage = "Some error occurred.";
    ui.displayErrorMessage(errorMessage);

    // Restore original cout
    std::cerr.rdbuf(oldCerr);

    // Compare captured output
    EXPECT_EQ(errorOutput.str(), expected);
}