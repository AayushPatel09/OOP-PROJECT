#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

// Function to get a validated integer input within an optional min and max range
int getValidatedInt(const std::string& prompt, int min = INT32_MIN, int max = INT32_MAX);

// Function to get a validated integer input that must be in a list of valid IDs
int getValidatedIntInList(const std::string& prompt, const std::vector<int>& validIDs);

// Function to get a validated non-empty string input
std::string getValidatedString(const std::string& prompt);

// Function to get a validated name string (could include specific validation rules)
std::string getValidatedName(const std::string& prompt);

// Function to get a validated phone number (likely numeric and length-checked)
int getValidatedPhone(const std::string& prompt);

// Function to get a validated filename string
std::string getValidatedFilename(const std::string& prompt);

#endif