/*
Provides basic functionality to store, retrieve, and manage passwords securely
 */

#ifndef PASSWORD_MANAGER_HPP
#define PASSWORD_MANAGER_HPP

#include <string>
#include <optional>
#include <vector>
#include <unordered_map>


// Why PasswordEntry is struct and not class? Simplistic data holder, no access control needed.
struct PasswordEntry {
    std::string site;
    std::string username;
    std::string password;
    std::optional<std::string> notes;  // Optional field for additional information
    std::vector<std::string> tags;  // Optional field to categorize the password entry
};


class PasswordManager {
public:
    // Adds a new password entry
    void addEntry(const PasswordEntry& entry);

    // Retrieves a password entry by site name
    // Why return std::optional? Entry might not exist, better than returning null pointer
    std::optional<PasswordEntry> getEntry(const std::string& site) const;

private:
    // Why unordered_map? Key-value pairs; search, insertion, and removal of elements
    // has complexity O(1); use site as key
    std::unordered_map<std::string, PasswordEntry> entries;
};

#endif //PASSWORD_MANAGER_HPP
