#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

// Truck class inherits from Vehicle
class Truck : public Vehicle {
private:
    int weightLimit;      // Maximum weight the truck can carry
    float additionalFee;  // Extra fee for renting the truck
public:
    // Constructor to initialize Truck with all attributes
    Truck(int VehicleId, std::string brand, int model, int year, int weightLimit, float additionalFee);

    // Calculate rental rate based on days (overrides Vehicle's method)
    double calculateRentalRate(int days) const override;

    // Display details about the truck
    void displayDetails() const;
};

#endif // TRUCK_H