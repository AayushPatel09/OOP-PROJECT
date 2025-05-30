#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "RentalManager.h"

// UIManager handles user interface operations and interacts with RentalManager
class UIManager {
private:
    RentalManager& manager;  // Reference to RentalManager for managing rentals

public:
    UIManager(RentalManager& rm);  // Constructor that initializes with a RentalManager reference
    void showMenu();               // Displays the main menu to the user
};

#endif