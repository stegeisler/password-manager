/*
Provides basic functionality to store, retrieve, and manage passwords securely
 */

#include "password_manager.hpp"
#include <optional>

void PasswordManager::addEntry(const PasswordEntry &entry) {
    entries[entry.site] = entry;
}

std::optional<PasswordEntry> PasswordManager::getEntry(const std::string &site) const {
    auto it = entries.find(site);
    if (it != entries.end()) {
        // Password entry found, return password entry (it->second: get value of it, not key)
        return it->second;
    } else {
        // Password entry NOT found, std::nullopt indicates that std::optional doesn't contain
        // a value
        return std::nullopt;
    }
}

