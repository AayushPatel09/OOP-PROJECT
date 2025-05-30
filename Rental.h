#ifndef RENTAL_H
#define RENTAL_H

#include "Vehicle.h"
#include "Customer.h"
#include <iostream>
#include <ctime>

using namespace std;

class Rental {
private:
    int rentalID;          // Unique ID for this rental
    Vehicle* vehicle;      // Pointer to the rented vehicle
    Customer* customer;    // Pointer to the customer renting the vehicle
    time_t startDate;      // Rental start date/time
    time_t endDate;        // Rental end date/time
    double totalCost;      // Total cost of the rental

public:
    // Constructor to create a Rental object
    // vehiceleId: rental ID
    // V: pointer to Vehicle being rented
    // C: pointer to Customer renting the vehicle
    // startDate: rental start time
    // endDate: rental end time
    Rental(int vehiceleId, Vehicle* V, Customer* C, time_t startDate, time_t endDate);

    double calculateTotal();     // Calculate total rental cost
    void printReceipt() const;   // Print rental receipt details

    Customer* getCustomer() const;   // Return pointer to customer
    int getID() const;               // Return rental ID
    Vehicle* getVehicle() const;     // Return pointer to vehicle
    time_t getStartDate() const;     // Return start date
    time_t getEndDate() const;       // Return end date
    double getTotalCost() const;     // Return total cost
};

#endif