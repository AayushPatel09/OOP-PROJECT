#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

// Returns the base rate of the car
float Car::getBaseRate() const {
    return baseRate;
}

// Calculates rental cost based on number of days
double Car::calculateRentalRate(int days) const {
    return baseRate * days;
}

// Constructs a Car with given vehicle ID, brand, model, year, and base rate
Car::Car(int Vehicleid, std::string brand, int model, int year, float baseRate) {
    this->vehicleId = Vehicleid;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->baseRate = baseRate;
}
