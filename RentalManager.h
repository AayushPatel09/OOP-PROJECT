#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include <vector>
#include "Rental.h"
#include "Vehicle.h"
#include "Customer.h"
#include <string>

class RentalManager {
private:
    std::vector<Rental> allRentals;          // Stores all rentals in the system
    std::vector<Vehicle*> availableVehicles; // Stores pointers to vehicles currently available for rent
    std::vector<Customer*> customers;        // Stores pointers to all registered customers

public:
    // Constructor to initialize RentalManager with vehicles and customers
    RentalManager(const std::vector<Vehicle*>& vehicles, const std::vector<Customer*>& customers);

    // Lists all vehicles that are currently available for rent
    void listAvailableVehicles() const;

    // Adds a new rental record with given vehicle and customer IDs and rental period
    void addRental(int vehicleID, int customerID, time_t start, time_t end);

    // Processes returning a vehicle based on rental ID
    void returnVehicle(int rentalID);

    // Shows all rentals associated with a specific customer ID
    void showCustomerRentals(int customerID) const;

    // Saves rental data to a file specified by filename
    void saveRentalsToFile(const std::string& filename) const;

    // Loads vehicles data from a file specified by filename
    void loadVehiclesFromFile(const std::string& filename);

    // Registers a new customer and saves to a file
    void registerNewCustomer(const std::string& filename);

    // Loads customer data from a file specified by filename
    void loadCustomersFromFile(const std::string& filename);

    // Loads rental records from a file specified by filename
    void loadRentalsFromFile(const std::string& filename);
};

#endif