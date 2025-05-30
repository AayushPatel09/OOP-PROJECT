// Represents a Car that can be rented.
// Inherits from the Vehicle class.

#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<string>
using namespace std;
#include"Vehicle.h"



class Car : public Vehicle{
    private:
    float baseRate;
    public:
    Car();
    // Constructor to initialize all Car attributes
    // Parameters:
    // - Vehicleid: Unique ID for the car
    // - brand: Car brand name
    // - model: Car model number
    // - year: Year of manufacture
    // - baseRate: Daily rental rate
    Car(int Vehicleid, std::string brand, int  model, int year, float baseRate);

       // Calculates the rental rate based on number of rental days
    double calculateRentalRate(int days) const override;


    float getBaseRate() const;
    // Returns the base rate of the car
};

#endif // CAR_H
