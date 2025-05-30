#include "ElectricCar.h"
#include <iostream>
using namespace std;

// Constructor initializes ElectricCar with a predefined base rate (e.g., 70.0)
ElectricCar::ElectricCar(int VehicleId, std::string brand, int model, int year)
    : Car(VehicleId, brand, model, year, 70.0)  // Set base rate for electric car
{
    // Initialization is handled by Car's constructor
}

// Displays charging-related details of the electric car
void ElectricCar::displayChargingInfo(int battery, float chargeTime) {
    cout << "\t\t\t\t\t\t\tVehicle ID: " << vehicleId << endl;
    cout << "\t\t\t\t\t\t\tBrand: " << brand << endl;
    cout << "\t\t\t\t\t\t\tModel: " << model << endl;
    cout << "\t\t\t\t\t\t\tYear: " << year << endl;
    cout << "\t\t\t\t\t\t\tStatus: " << (isRented ? "Not available" : "Available") << endl;
    cout << "\t\t\t\t\t\t\tBattery is at " << battery << "%\n";
    cout << "\t\t\t\t\t\t\tApprox Charging time: " << chargeTime << " hours\n";
}

// Calculates total rental cost based on days and base rate
double ElectricCar::calculateRentalRate(int days) const {
    return getBaseRate() * days;
}