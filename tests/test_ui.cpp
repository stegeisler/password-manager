#include "ui.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

// Test UI welcome message function
TEST(UITest, WelcomeMessage) {
    UI ui;
    const std::string expected = "Welcome to the Password Manager!\nPlease enter your master password to continue.\n";

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
