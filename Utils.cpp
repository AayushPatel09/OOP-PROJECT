#include "Utils.h"
#include <iostream>
#include <limits>
#include <regex>

// Get an integer input from user between min and max (inclusive)
int getValidatedInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << "\t\t\t\t\t\t\t" << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            return value;
        }
        std::cout << "\t\t\t\t\t\t\tInvalid input. Please enter a number";
        if (min != INT32_MIN || max != INT32_MAX)
            std::cout << " between " << min << " and " << max;
        std::cout << ".\n";

        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
}

// Get an integer input that must be one of the valid IDs provided
int getValidatedIntInList(const std::string& prompt, const std::vector<int>& validIDs) {
    int value;
    while (true) {
        std::cout << "\t\t\t\t\t\t\t" << prompt;
        if (std::cin >> value) {
            for (int id : validIDs) {
                if (value == id) {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return value;
                }
            }
        }
        std::cout << "\t\t\t\t\t\t\tInvalid input. Please enter a valid ID.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Get a non-empty string input from user
std::string getValidatedString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << "\t\t\t\t\t\t\t" << prompt;
        std::getline(std::cin, input);
        if (!input.empty())
            return input;
        std::cout << "\t\t\t\t\t\t\tInput cannot be empty. Try again.\n";
    }
}

// Get a validated name string containing only letters and spaces
std::string getValidatedName(const std::string& prompt) {
    std::string name;
    std::regex nameRegex("^[A-Za-z ]+$");
    while (true) {
        name = getValidatedString(prompt);
        if (std::regex_match(name, nameRegex))
            return name;
        std::cout << "\t\t\t\t\t\t\tInvalid name. Only letters and spaces allowed.\n";
    }
}

// Get a phone number input with at least 7 digits
int getValidatedPhone(const std::string& prompt) {
    std::string phone;
    std::regex phoneRegex("^\\d{7,}$");  // at least 7 digits
    while (true) {
        std::cout << "\t\t\t\t\t\t\t" << prompt;
        std::getline(std::cin, phone);
        if (std::regex_match(phone, phoneRegex)) {
            return std::stoi(phone);
        }
        std::cout << "\t\t\t\t\t\t\tInvalid phone number. Must be at least 7 digits.\n";
    }
}

// Get a valid filename string (only letters, numbers, -, _, and . allowed)
std::string getValidatedFilename(const std::string& prompt) {
    std::string filename;
    std::regex filenameRegex("^[A-Za-z0-9_\\-\\.]+$");
    while (true) {
        std::cout << "\t\t\t\t\t\t\t" << prompt;
        std::getline(std::cin, filename);
        if (std::regex_match(filename, filenameRegex) && !filename.empty())
            return filename;
        std::cout << "\t\t\t\t\t\t\tInvalid filename. Use only letters, numbers, -, _, or .\n";
    }
}
