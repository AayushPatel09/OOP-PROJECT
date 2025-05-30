#include <iostream>
#include <vector>
#include <string>
#include <limits> // Required for numeric_limits
#include <stdexcept> // Required for runtime_error
#include "RentalManager.h"
#include "Vehicle.h" 
#include "Car.h"
#include "Truck.h"
#include "ElectricCar.h"
#include "Customer.h"
#include "Rental.h"
#include "Utils.h"     // For getValidatedName, getValidatedPhone

int main() {
    // Initialize RentalManager with empty vectors; data will be loaded from files.
    std::vector<Vehicle*> initialVehicles;
    std::vector<Customer*> initialCustomers;
    RentalManager rentalManager(initialVehicles, initialCustomers);

    const std::string vehiclesFile = "vehicles.txt";
    const std::string customersFile = "customers.txt";
    const std::string rentalsFile = "rentals.txt";

    std::cout << "\n--- Rental System Initializing ---\n";

    // 1. Load data from files
    try {
        std::cout << "\n--- Loading Vehicles ---\n";
        rentalManager.loadVehiclesFromFile(vehiclesFile);
        std::cout << "\n--- Loading Customers ---\n";
        rentalManager.loadCustomersFromFile(customersFile);
        std::cout << "\n--- Loading Rentals ---\n";
        rentalManager.loadRentalsFromFile(rentalsFile);
    } catch (const std::exception& e) {
        std::cerr << "Error during initial loading: " << e.what() << std::endl;
        return 1; // Exit if essential files can't be loaded
    }
    // Listing rental vehicles
    std::cout << "\n\n--- Listing Available Vehicles ---\n";
    rentalManager.listAvailableVehicles();

    // Registering a new customer
    std::cout << "\n\n--- Registering New Customer ---\n";
    // Note: getValidatedName and getValidatedPhone are assumed to be in Utils.h
    // and handle their own input prompts as per RentalManager.cpp.
    // The calls within registerNewCustomer will prompt the user.
    rentalManager.registerNewCustomer(customersFile);

    // For addRental, we need a customer ID and vehicle ID
    int vehicleIDToRent;
    int customerIDForRental;
    time_t rentalStartDate = time(nullptr); // Current time as start date

    std::cout << "\n\n--- Adding a New Rental ---\n";
    std::cout << "\t\t\t\t\t\t\tEnter Vehicle ID to rent: ";
    while (!(std::cin >> vehicleIDToRent)) {
        std::cout << "\t\t\t\t\t\t\tInvalid input. Enter a numeric Vehicle ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume newline

    std::cout << "\t\t\t\t\t\t\tEnter Customer ID for this rental: ";
    while (!(std::cin >> customerIDForRental)) {
        std::cout << "\t\t\t\t\t\t\tInvalid input. Enter a numeric Customer ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume newline

    // The addRental function will ask for the number of days
    rentalManager.addRental(vehicleIDToRent, customerIDForRental, rentalStartDate, 0 /*end date is calculated inside*/);

    // Showing customer rentals
    std::cout << "\n\n--- Showing Rentals for Customer ID " << customerIDForRental << " ---\n";
    rentalManager.showCustomerRentals(customerIDForRental);

    // To test returnVehicle, we need a rental ID.
    // Assuming the rental added above was successful and is the latest one.
    // Or, if allRentals is accessible or has a getter, you could retrieve the last ID.
    // For simplicity, let's ask the user.
    // returning a vehicle
    int rentalIDToReturn;
    std::cout << "\n\n--- Returning a Vehicle ---\n";
    std::cout << "\t\t\t\t\t\t\tEnter Rental ID to return: ";
    while (!(std::cin >> rentalIDToReturn)) {
        std::cout << "\t\t\t\t\t\t\tInvalid input. Enter a numeric Rental ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume newline

    rentalManager.returnVehicle(rentalIDToReturn);

    std::cout << "\n\n--- Listing Available Vehicles After Return ---\n";
    rentalManager.listAvailableVehicles();

    // Saving all rental data
    std::cout << "\n\n--- Saving All Rental Data (Final) ---\n";
    // Note: returnVehicle also calls saveRentalsToFile. This is an explicit final save.
    rentalManager.saveRentalsToFile(rentalsFile);
    std::cout << "\n\n--- Test Operations Complete ---\n";
    return 0;
}
