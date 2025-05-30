#include "Truck.h"
#include <iostream>
using namespace std;

Truck::Truck(int VehicleId, std::string brand, int model, int year, int weightLimit, float additionalFee)
    : Vehicle(VehicleId, brand, model, year, false),  // Initialize base class properly
      weightLimit(weightLimit), additionalFee(additionalFee) {}

double Truck::calculateRentalRate(int days) const {
    // Example: base rate is $100 + additional fee
    return 100.0 * days + additionalFee;
}

void Truck::displayDetails() const {
    cout << "\t\t\t\t\t\t\tVehicle ID: " << vehicleId << endl;
    cout << "\t\t\t\t\t\t\tBrand: " << brand << endl;
    cout << "\t\t\t\t\t\t\tModel: " << model << endl;
    cout << "\t\t\t\t\t\t\tYear: " << year << endl;
    cout << "\t\t\t\t\t\t\tStatus: " << (isRented ? "Not available" : "Available") << endl;
    cout << "\t\t\t\t\t\t\tWeight Limit: " << weightLimit << " kg" << endl;
    cout << "\t\t\t\t\t\t\tAdditional Fee: $" << additionalFee << endl;
}