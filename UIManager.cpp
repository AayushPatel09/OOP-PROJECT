#include "UIManager.h"
#include "Utils.h"
#include <iostream>
#include <ctime>

// Constructor initializes UIManager with a reference to RentalManager
UIManager::UIManager(RentalManager& rm) : manager(rm) {}

// Main menu loop for user interaction
void UIManager::showMenu() {
    int choice;

    do {
        // Display menu options
        std::cout << "\n\t\t\t\t\t\t\t--- Vehicle Rental System --- \n\n";
        std::cout << "\t\t\t\t\t\t\t1. View Available Vehicles\n";
        std::cout << "\t\t\t\t\t\t\t2. Rent a Vehicle\n";
        std::cout << "\t\t\t\t\t\t\t3. Return a Vehicle (by Rental ID)\n";
        std::cout << "\t\t\t\t\t\t\t4. View Customer Rental History\n";
        std::cout << "\t\t\t\t\t\t\t5. Save Rental History to File\n";
        std::cout << "\t\t\t\t\t\t\t6. Register New Customer\n";
        std::cout << "\t\t\t\t\t\t\t7. Exit\n\n";

        // Get user's menu choice, validated between 1 and 7
        choice = getValidatedInt("Enter your choice (1–7): ", 1, 7);

        int vehicleID, customerID, rentalID;
        time_t start, end;

        // Handle user's choice
        switch (choice) {
            case 1: {
                // Load vehicles from file and list available ones
                try {
                    manager.loadVehiclesFromFile("vehicles.txt");
                } catch (const std::exception& e) {
                    std::cerr << "\t\t\t\t\t\t\tError loading vehicles: " << e.what() << std::endl;
                    break;
                }

                std::cout << "\n\t\t\t\t\t\t\t--- Available Vehicles ---\n";
                manager.listAvailableVehicles();
                break;
            }

            case 2:
                // Rent a vehicle: get vehicle and customer IDs, start time now, default 2 days rental
                vehicleID = getValidatedInt("Enter Vehicle ID: ");
                customerID = getValidatedInt("Enter Customer ID: ");
                time(&start);
                end = start + 2 * 86400;  // 2-day rental by default (2 * 24 * 60 * 60 seconds)
                manager.addRental(vehicleID, customerID, start, end);
                break;

            case 3:
                // Return a vehicle by rental ID
                rentalID = getValidatedInt("Enter Rental ID to return: ");
                manager.returnVehicle(rentalID);
                break;

            case 4:
                // Show rental history for a specific customer
                customerID = getValidatedInt("Enter Customer ID: ");
                manager.showCustomerRentals(customerID);
                break;

            case 5:
                // Save all rentals to file
                std::cout << "\n\t\t\t\t\t\t\tSaving rental history to 'rentals.txt'...\n";
                manager.saveRentalsToFile("rentals.txt");
                break;

            case 6:
                // Register a new customer and save to file
                manager.registerNewCustomer("customers.txt");
                break;

            case 7:
                // Exit the program
                std::cout << "\t\t\t\t\t\t\tExiting...\n";
                break;

            default:
                // Handle invalid options (shouldn't happen due to validation)
                std::cout << "\t\t\t\t\t\t\tInvalid option. Please choose 1–7.\n";
        }

    } while (choice != 7); // Continue until user chooses to exit
}