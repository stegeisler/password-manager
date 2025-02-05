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

// Test UI get master password function
TEST(UITest, ReadMasterPassword) {
    UI ui;

    // Simulated user input
    std::istringstream input("secure123\n");

    // Redirect std::cin
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    // Get simulated master password
    std::string password = ui.getMasterPassword();

    // Restore std::cin
    std::cin.rdbuf(oldCin);

    // Check if the function returned the correct password
    std::string expected = "secure123";
    EXPECT_EQ(password, expected);
}

// TODO: Make all test that read from std::cin use UIUserInputTestFixture class
// TODO: Write similar class as UIUserInputTestFixture for tests that write to std::cout

// Provides a common setup and teardown mechanism for multiple test cases
// Use public inheritance, because Google Test requires SetUp() and TearDown() to be public
class UIUserInputTestFixture : public ::testing::Test {
    // protected allows test functions to access ui, input, oldCin, SetUp(),
    // TearDown(), and simulateInput(), but prevents external code from accidental
    // modification of internal test states
protected:
    UI ui;
    // Redirect std::cin to use input instead of actual user input
    std::istringstream input;

    // - oldCin stores the original std::cin stream buffer, so we can restore the original
    // std::cin after each test
    // - Raw pointer is used here instead of smart pointer, because std::streambuf object
    // is owned by std::cin and smart pointer would try to delete this object, when it goes
    // out of scope, but we restore the original buffer after the test.
    std::streambuf* oldCin;

    // Runs before each test case
    void SetUp() override {
        // Save original cin buffer
        oldCin = std::cin.rdbuf();
    }

    // Runs after each test case
    void TearDown() override {
        // Restore cin after test
        std::cin.rdbuf(oldCin);
    }

    // Automates testing of functions that read from std::cin
    void simulateInput(const std::string& simulatedInput) {
        // Stores simulatedInput in std::istringstream input
        input.str(simulatedInput);
        // Redirect cin to our test input
        std::cin.rdbuf(input.rdbuf());
    }
};

// Test case 1: Basic input handling (notes and tags are empty)
TEST_F(UIUserInputTestFixture, GetPasswordEntry_BasicInput) {
    simulateInput("example.com\nuser123\nmypassword\n\n\n");

    PasswordEntry entry = ui.getPasswordEntry();

    EXPECT_EQ(entry.site, "example.com");
    EXPECT_EQ(entry.username, "user123");
    EXPECT_EQ(entry.password, "mypassword");
    EXPECT_FALSE(entry.notes.has_value());  // Notes should be empty
    EXPECT_TRUE(entry.tags.empty());        // No tags entered
}

// Test case 2: User enters notes
TEST_F(UIUserInputTestFixture, GetPasswordEntry_WithNotes) {
    simulateInput("example.com\nuser123\nmypassword\nMy secret note\n\n");

    PasswordEntry entry = ui.getPasswordEntry();

    EXPECT_EQ(entry.site, "example.com");
    EXPECT_EQ(entry.username, "user123");
    EXPECT_EQ(entry.password, "mypassword");
    ASSERT_TRUE(entry.notes.has_value());
    EXPECT_EQ(entry.notes.value(), "My secret note");
    EXPECT_TRUE(entry.tags.empty());
}

// Test case 3: User enters multiple tags
TEST_F(UIUserInputTestFixture, GetPasswordEntry_WithTags) {
    simulateInput("example.com\nuser123\nmypassword\n\nwork,personal,finance\n");

    PasswordEntry entry = ui.getPasswordEntry();

    EXPECT_EQ(entry.site, "example.com");
    EXPECT_EQ(entry.username, "user123");
    EXPECT_EQ(entry.password, "mypassword");
    EXPECT_FALSE(entry.notes.has_value());
    ASSERT_EQ(entry.tags.size(), 3);
    EXPECT_EQ(entry.tags[0], "work");
    EXPECT_EQ(entry.tags[1], "personal");
    EXPECT_EQ(entry.tags[2], "finance");
}

// Test case 4: User provides notes and tags
TEST_F(UIUserInputTestFixture, GetPasswordEntry_WithNotesAndTags) {
    simulateInput("example.com\nuser123\nmypassword\nImportant account\nwork,security\n");

    PasswordEntry entry = ui.getPasswordEntry();

    EXPECT_EQ(entry.site, "example.com");
    EXPECT_EQ(entry.username, "user123");
    EXPECT_EQ(entry.password, "mypassword");
    ASSERT_TRUE(entry.notes.has_value());
    EXPECT_EQ(entry.notes.value(), "Important account");
    ASSERT_EQ(entry.tags.size(), 2);
    EXPECT_EQ(entry.tags[0], "work");
    EXPECT_EQ(entry.tags[1], "security");
}

// Test case 5: User provides empty input fields
TEST_F(UIUserInputTestFixture, GetPasswordEntry_EmptyFields) {
    simulateInput("\n\n\n\n\n");

    PasswordEntry entry = ui.getPasswordEntry();

    EXPECT_EQ(entry.site, "");
    EXPECT_EQ(entry.username, "");
    EXPECT_EQ(entry.password, "");
    EXPECT_FALSE(entry.notes.has_value());
    EXPECT_TRUE(entry.tags.empty());
}