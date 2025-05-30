#include <iostream>
#include <vector>
#include <limits>
#include "Utils.h"

using namespace std;

int main() {
    // Test getValidatedInt
    cout << "Testing getValidatedInt..." << endl;
    int validInt = getValidatedInt("Enter a number between 1 and 10: ", 1, 10);
    cout << "You entered a valid number: " << validInt << endl;
    
    // Test getValidatedIntInList
    cout << "Testing getValidatedIntInList..." << endl;
    vector<int> validIDs = {101, 102, 103};
    int validID = getValidatedIntInList("Enter a valid vehicle ID from [101, 102, 103]: ", validIDs);
    cout << "You entered a valid vehicle ID: " << validID << endl;

    // Test getValidatedString
    cout << "Testing getValidatedString..." << endl;
    string validString = getValidatedString("Enter a valid string: ");
    cout << "You entered a valid string: " << validString << endl;

    // Test getValidatedName
    cout << "Testing getValidatedName..." << endl;
    string validName = getValidatedName("Enter a valid name: ");
    cout << "You entered a valid name: " << validName << endl;

    // Test getValidatedPhone
    cout << "Testing getValidatedPhone..." << endl;
    int validPhone = getValidatedPhone("Enter a valid phone number: ");
    cout << "You entered a valid phone number: " << validPhone << endl;

    // Test getValidatedFilename
    cout << "Testing getValidatedFilename..." << endl;
    string validFilename = getValidatedFilename("Enter a valid filename: ");
    cout << "You entered a valid filename: " << validFilename << endl;

    return 0;
}
