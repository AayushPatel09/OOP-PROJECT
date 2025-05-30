#include "Vehicle.h"
#include "Customer.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Rental.h"

using namespace std;

// Constructor to initialize Rental object with given details
Rental::Rental(int Id, Vehicle* V, Customer* C, time_t startDate, time_t endDate) {
    this->rentalID = Id;
    this->vehicle = V;
    this->customer = C;
    this->startDate = startDate;
    this->endDate = endDate;
    totalCost = 0;  // Initialize total cost to zero
}

// Returns the customer pointer associated with this rental
Customer* Rental::getCustomer() const {
    return customer;
}

// Calculates the total cost of rental based on the duration
double Rental::calculateTotal() {
    // Calculate number of days between start and end dates
    double days = difftime(endDate, startDate) / (60 * 60 * 24);
    // Calculate total rental cost using vehicle's rental rate
    totalCost = vehicle->calculateRentalRate(static_cast<int>(days));
    return totalCost;
}

// Prints a formatted rental receipt with all relevant details
void Rental::printReceipt() const {
    cout << "\n\t\t\t\t\t\t\tRental Receipt" << endl;
    cout << "\t\t\t\t\t\t\tRental ID: " << rentalID << endl;
    cout << "\t\t\t\t\t\t\tVehicle ID: " << vehicle->getVehicleId() << endl;
    cout << "\t\t\t\t\t\t\tCustomer Name: " << customer->getName() << endl;
    cout << "\t\t\t\t\t\t\tStart Date: " << ctime(&startDate);
    cout << "\t\t\t\t\t\t\tEnd Date: " << ctime(&endDate);
    cout << fixed << setprecision(2) << "\t\t\t\t\t\t\tTotal Cost: $" << totalCost << endl;
}