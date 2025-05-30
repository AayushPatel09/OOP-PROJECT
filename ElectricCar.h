#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include <iostream>
#include "Car.h"
#include "Rental.h"
#include "Vehicle.h"

using namespace std;

// Class representing an electric car, inheriting from Car
class ElectricCar : public Car {
private:
    int battery;         // Battery percentage or capacity (can be extended)
    float chargeTime;    // Estimated charging time in hours

public:
    // Constructor to initialize ElectricCar with basic vehicle details
    ElectricCar(int Vehicleid, std::string brand, int model, int year);

    // Displays charging-related information
    void displayChargingInfo(int battery, float chargeTime);

    // Calculates rental rate for electric car (can be different from regular car)
    double calculateRentalRate(int days) const override;
};

#endif