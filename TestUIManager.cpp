#include <iostream>
#include <vector>   // For initial empty vectors for RentalManager
#include <string>   // For filenames
#include <stdexcept> // For exception handling

// Your project's header files
#include "RentalManager.h" // Assumed to be complete and working
#include "UIManager.h"     // The class to be tested
#include "Utils.h"         // For getValidatedInt and other utilities

// Note: Ensure that RentalManager.h includes its own dependencies like Vehicle.h, Customer.h etc.
// or that they are included here if RentalManager's interface exposes them directly in a way
// that this main file would need them. Usually, RentalManager.h should be self-contained.

// Also ensure Customer::nextID is defined in Customer.cpp (e.g., int Customer::nextID = 1;)

int main() {
    std::cout << "--- Rental System Application Starting ---" << std::endl;

    // 1. Initialize RentalManager
    // RentalManager is initialized with empty vectors; data will be loaded from files
    // either by explicit calls here or through UIManager options.
    std::vector<Vehicle*> initialVehicles;
    std::vector<Customer*> initialCustomers;
    RentalManager rentalMgr(initialVehicles, initialCustomers);

    // It's good practice to pre-load essential data for a smoother UI experience,
    // especially customers and any existing rental history.
    // UIManager's "View Available Vehicles" also reloads vehicles, which might be redundant
    // if loaded here, but ensures freshness.
    try {
        std::cout << "\nMain: Initializing essential Rental Manager data..." << std::endl;
        
        // Load customers - usually needed for renting
        rentalMgr.loadCustomersFromFile("customers.txt");
        
        // Load existing rental history - important for context and returns
        rentalMgr.loadRentalsFromFile("rentals.txt");

        // Optionally load vehicles here too, or let UIManager's option 1 handle it.
        // If loaded here, UIManager's option 1 will reload them.
        // rentalMgr.loadVehiclesFromFile("vehicles.txt"); 
        
        std::cout << "Main: Essential Rental Manager data initialized." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Main: Error during initial RentalManager data loading: " << e.what() << std::endl;
        std::cerr << "Main: The system may not function correctly. Please check data files." << std::endl;
        // You might choose to exit here if these are critical:
        // return 1;
    }

    // 2. Create UIManager instance, passing the RentalManager
    UIManager ui(rentalMgr);

    // 3. Show the menu and start the user interaction loop
    // All "testing" from this point is done by interacting with the UIManager's menu.
    ui.showMenu();

    // The showMenu() function will loop until the user chooses to exit.
    // After exiting the menu:
    std::cout << "\n--- Rental System Application Terminating ---" << std::endl;

    // The RentalManager destructor (if implemented correctly) will be called automatically
    // when `rentalMgr` goes out of scope, cleaning up dynamically allocated memory
    // for vehicles and customers.

    return 0; // Indicates successful execution
}