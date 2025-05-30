#include <fstream>
#include <sstream>
#include <stdexcept>
#include "RentalManager.h"
#include "Car.h"
#include "Truck.h"
#include "ElectricCar.h"
#include "Utils.h"
#include "Customer.h"
#include <limits>
#include <iomanip>
#include <cstdio>
#include <sstream>

// Constructor: Initialize RentalManager with given vectors of vehicles and customers
RentalManager::RentalManager(const std::vector<Vehicle*>& vehicles, const std::vector<Customer*>& customers) {
    availableVehicles = vehicles;
    this->customers = customers;
}

// Lists all vehicles that are currently available for rent
void RentalManager::listAvailableVehicles() const {
    for (int i = 0; i < availableVehicles.size(); i++) {
        if (availableVehicles[i]->isAvailable()) {  // Only show available vehicles
            availableVehicles[i]->displayDetails(); // Display details of the vehicle
            std::cout << "\t\t\t\t\t\t----------------------------------------------\n";
        }
    }
}

// Add a new rental given vehicle and customer IDs and rental start time
void RentalManager::addRental(int vehicleID, int customerID, time_t start, time_t /*end*/) {
    Vehicle* selectedVehicle = nullptr;
    Customer* selectedCustomer = nullptr;

    int days;
    std::cout << "\t\t\t\t\t\t\tEnter number of rental days: ";
    // Input validation for rental days (must be positive integer)
    while (!(std::cin >> days) || days <= 0) {
        std::cout << "\t\t\t\t\t\t\tInvalid input. Enter a positive number of days: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Calculate rental end date/time based on days entered
    time_t end = start + (days * 24 * 60 * 60);  // seconds in a day

    // Find vehicle with matching ID and mark it as rented if possible
    for (std::size_t i = 0; i < availableVehicles.size(); i++) {
        if (availableVehicles[i]->getVehicleId() == vehicleID && availableVehicles[i]->rentVehicle()) {
            selectedVehicle = availableVehicles[i];
            break;
        }
    }

    // Find customer with matching ID
    for (std::size_t i = 0; i < customers.size(); i++) {
        if (customers[i]->getID() == customerID) {
            selectedCustomer = customers[i];
            break;
        }
    }

    // If both vehicle and customer are found, create a new rental
    if (selectedVehicle && selectedCustomer) {
        int rentalID = allRentals.size() + 1; // Generate new rental ID based on count
        Rental rental(rentalID, selectedVehicle, selectedCustomer, start, end);
        rental.calculateTotal();  // Calculate rental cost

        rental.printReceipt();  // Print rental receipt details

        allRentals.push_back(rental);  // Add rental to list
        std::cout << "\t\t\t\t\t\t\tRental created successfully.\n";
    } else {
        std::cout << "\t\t\t\t\t\t\tError: Invalid customer or vehicle.\n";
    }
}

// Return a vehicle by rental ID, mark vehicle as available again, and remove rental from list
void RentalManager::returnVehicle(int rentalID) {
    bool rentalFound = false;

    // Iterate rentals to find the matching rental ID
    for (auto it = allRentals.begin(); it != allRentals.end(); ++it) {
        if (it->getID() == rentalID) {
            Vehicle* vehicle = it->getVehicle();
            vehicle->returnvehicle();  // Mark vehicle as returned (available)

            it->printReceipt();  // Print receipt on return

            std::cout << "\t\t\t\t\t\t\tVehicle " << vehicle->getVehicleId() << " returned successfully.\n";

            allRentals.erase(it);  // Remove rental from the active list

            saveRentalsToFile("rentals.txt");  // Update rentals file after removal

            rentalFound = true;
            break;
        }
    }

    if (!rentalFound) {
        std::cout << "\t\t\t\t\t\t\tRental ID not found.\n";
    }
}

#include <iomanip>
#include <ctime>
#include <sstream>

// Load rentals from file, parse data, and populate allRentals vector
void RentalManager::loadRentalsFromFile(const std::string& filename) {
    allRentals.clear();  // Clear current rentals list before loading

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "\t\t\t\t\t\t\tCould not open rentals file: " << filename << "\n";
        return;
    }

    std::string line;
    int rentalID = 0;
    int vehicleID = 0;
    int customerID = 0;
    time_t start = 0;
    time_t end = 0;
    double totalCost = 0;

    // Read file line by line and parse rental information
    while (std::getline(file, line)) {
        if (line.rfind("Rental ID:", 0) == 0) {  // Line starts with "Rental ID:"
            rentalID = std::stoi(line.substr(10));
        } else if (line.rfind("Customer ID:", 0) == 0) {
            customerID = std::stoi(line.substr(12));  // Extract customer ID
        } else if (line.rfind("Vehicle ID:", 0) == 0) {
            vehicleID = std::stoi(line.substr(11));   // Extract vehicle ID
        } else if (line.rfind("Start:", 0) == 0) {
            std::string timeStr = line.substr(6);
            struct tm tm = {};
            std::istringstream ss(timeStr);
            ss >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y");  // Parse date/time string
            start = mktime(&tm);
        } else if (line.rfind("End:", 0) == 0) {
            std::string timeStr = line.substr(4);
            struct tm tm = {};
            std::istringstream ss(timeStr);
            ss >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y");
            end = mktime(&tm);
        } else if (line.rfind("Total Cost:", 0) == 0) {
            std::string costStr = line.substr(12);
            size_t dollarPos = costStr.find('$');
            if (dollarPos != std::string::npos)
                costStr = costStr.substr(dollarPos + 1);
            try {
                totalCost = std::stod(costStr);
            } catch (...) {
                std::cerr << "\t\t\t\t\t\t\tInvalid total cost format: " << costStr << "\n";
                totalCost = 0;
            }

            // After parsing one full rental entry, find vehicle and customer objects
            Vehicle* v = nullptr;
            Customer* c = nullptr;

            for (int i = 0; i < availableVehicles.size(); i++) {
                if (availableVehicles[i]->getVehicleId() == vehicleID) {
                    v = availableVehicles[i];
                    break;
                }
            }

            for (int j = 0; j < customers.size(); j++) {
                if (customers[j]->getID() == customerID) {
                    c = customers[j];
                    break;
                }
            }

            if (v && c) {
                Rental r(rentalID, v, c, start, end);
                r.calculateTotal();  // Calculate cost (can also assign totalCost if you want to keep original)
                allRentals.push_back(r);
                v->markAsRented();  // Mark vehicle as rented in memory
            } else {
                if (!v) std::cerr << "\t\t\t\t\t\t\tWarning: Vehicle ID " << vehicleID << " not found.\n";
                if (!c) std::cerr << "\t\t\t\t\t\t\tWarning: Customer ID " << customerID << " not found.\n";
            }
        }
    }

    file.close();
    std::cout << "\t\t\t\t\t\t\tRentals loaded from '" << filename << "'\n";
}

// Display all rentals for a specific customer ID
void RentalManager::showCustomerRentals(int customerID) const {
    bool found = false;
    for (const auto& rental : allRentals) {
        if (rental.getCustomer()->getID() == customerID) {
            rental.printReceipt();  // Print rental receipt for each match
            found = true;
        }
    }
    if (!found) {
        std::cout << "\t\t\t\t\t\t\tNo rentals found for customer ID: " << customerID << std::endl;
    }
}

// Save all current rentals to a file (used after updates)
void RentalManager::saveRentalsToFile(const std::string& filename) const {
    try {
        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            throw std::ios_base::failure("\t\t\t\t\t\t\tFailed to open file for writing.");
        }

        // Write each rental's info to file with formatting
        for (const Rental& rental : allRentals) {
            time_t start = rental.getStartDate();
            time_t end = rental.getEndDate();

            outFile << "Rental ID: " << rental.getID() << "\n";
            outFile << "Customer ID: " << rental.getCustomer()->getID() << "\n";  // Save IDs, not names
            outFile << "Vehicle ID: " << rental.getVehicle()->getVehicleId() << "\n";
            outFile << "Start: " << std::ctime(&start);  // ctime adds newline
            outFile << "End: " << std::ctime(&end);
            outFile << std::fixed << std::setprecision(2);
            outFile << "Total Cost: $" << rental.getTotalCost() << "\n";
            outFile << "-----------------------------\n";
        }

        std::cout << "\t\t\t\t\t\t\tRental history saved to '" << filename << "'\n";

    } catch (const std::exception& e) {
        std::cerr << "\t\t\t\t\t\t\tError saving rentals to file: " << e.what() << std::endl;
    }
}

// Register a new customer by taking input and appending to file
void RentalManager::registerNewCustomer(const std::string& filename) {
    std::string name;
    int phone;

    // Utility functions ensure valid input for name and phone number
    name = getValidatedName("Enter customer name: ");
    phone = getValidatedPhone("Enter phone number: ");

    Customer* newCustomer = new Customer(name, phone);  // Create new customer object
    customers.push_back(newCustomer);                    // Add to customer list

    // Append new customer info to file
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "\t\t\t\t\t\t\tFailed to open customer file for writing.\n";
        return;
    }

    outFile << newCustomer->getID() << "," << name << "," << phone << "\n";
    outFile.close();

    std::cout << "\t\t\t\t\t\t\tCustomer registered successfully! ID: "
              << newCustomer->getID() << "\n";
}

// Load customers from file and create Customer objects in memory
void RentalManager::loadCustomersFromFile(const std::string& filename) {
    customers.clear();

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open customer file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);

        // Parse CSV line: ID,Name,Phone
        std::string idStr, name, phoneStr;
        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        std::getline(ss, phoneStr);

        int id = std::stoi(idStr);
        int phone = std::stoi(phoneStr);

        customers.push_back(new Customer(id, name, phone));
    }

    // Update static nextID in Customer class to avoid duplicate IDs
    int maxID = 0;
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i]->getID() > maxID)
            maxID = customers[i]->getID();
    }
    Customer::nextID = maxID + 1;

    file.close();
    std::cout << "\t\t\t\t\t\t\tCustomers loaded successfully from '" << filename << "'\n";
}

#include "Rental.h"

// Rental class accessor methods
int Rental::getID() const {
    return rentalID;
}

Vehicle* Rental::getVehicle() const {
    return vehicle;
}

time_t Rental::getStartDate() const {
    return startDate;
}

time_t Rental::getEndDate() const {
    return endDate;
}

double Rental::getTotalCost() const {
    return totalCost;
}

// Load vehicles from file, clearing old list first to avoid leaks
void RentalManager::loadVehiclesFromFile(const std::string& filename) {
    // Delete existing vehicles to avoid memory leaks
    for (int i = 0; i < availableVehicles.size(); i++) {
        delete availableVehicles[i];
    }
    availableVehicles.clear();

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("\t\t\t\t\t\t\tCannot open vehicle file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        getline(ss, type, ',');

        // Parse each vehicle type accordingly
        if (type == "Car") {
            int id, model, year;
            std::string brand;
            float rate;
            char delim;

            ss >> id >> delim;
            getline(ss, brand, ',');
            ss >> model >> delim >> year >> delim >> rate;

            availableVehicles.push_back(new Car(id, brand, model, year, rate));
        } else if (type == "Truck") {
            int id, model, year, weightLimit;
            std::string brand;
            float fee;
            char delim;

            ss >> id >> delim;
            getline(ss, brand, ',');
            ss >> model >> delim >> year >> delim >> weightLimit >> delim >> fee;

            availableVehicles.push_back(new Truck(id, brand, model, year, weightLimit, fee));
        } else if (type == "ElectricCar") {
            int id, model, year;
            std::string brand;
            char delim;

            ss >> id >> delim;
            getline(ss, brand, ',');
            ss >> model >> delim >> year;

            availableVehicles.push_back(new ElectricCar(id, brand, model, year));
        }
    }

    file.close();
    std::cout << "\t\t\t\t\t\t\tVehicles loaded successfully from '" << filename << "'\n";
}