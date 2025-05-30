#include "Car.h"
#include <iostream>

using namespace std;

int main() {
    // Create a Car object (derived class of Vehicle) for testing
    Car testCar(1001, "Toyota", 2023, 2025, false); // Initial status: not rented

    // Test Constructor and Getter for Vehicle ID
    if (testCar.getVehicleId() == 1001) {
        cout << "Constructor and Getter Test PASSED\n";
    } else {
        cout << "Constructor and Getter Test FAILED\n";
    }

    // Test Display Details
    cout << "\nTesting Display Details:\n";
    testCar.displayDetails(); // Display the vehicle's information

    // Test Renting the Vehicle
    if (testCar.rentVehicle()) {
        cout << "Renting Test PASSED\n";
    } else {
        cout << "Renting Test FAILED\n";
    }

    // Try Renting the Vehicle Again (should fail since it's already rented)
    if (!testCar.rentVehicle()) {
        cout << "Rent Again Test PASSED\n";
    } else {
        cout << "Rent Again Test FAILED\n";
    }

    // Test Returning the Vehicle
    if (testCar.returnvehicle()) {
        cout << "Returning Test PASSED\n";
    } else {
        cout << "Returning Test FAILED\n";
    }

    // Try Returning the Vehicle Again (should fail since it's already available)
    if (!testCar.returnvehicle()) {
        cout << "Return Again Test PASSED\n";
    } else {
        cout << "Return Again Test FAILED\n";
    }

    // Test Availability Check after renting and returning the vehicle
    if (testCar.isAvailable()) {
        cout << "Availability Test PASSED - Vehicle is available.\n";
    } else {
        cout << "Availability Test FAILED - Vehicle is not available.\n";
    }

    // Rent the vehicle again and check availability
    testCar.rentVehicle();
    if (!testCar.isAvailable()) {
        cout << "Availability Test PASSED - Vehicle is rented.\n";
    } else {
        cout << "Availability Test FAILED - Vehicle is still available.\n";
    }

    cout << "All tests completed.\n";

    return 0;
}
