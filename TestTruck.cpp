#include "Truck.h"
#include <iostream>
#include"Vehicle.h"

using namespace std;

int main() {
    // Create a Truck object for testing
    Truck testTruck(201, "Ford", 2023, 2025, 5000, 80.0f); // Weight limit: 5000 kg, Additional fee: $50.0

    // Test Constructor and Getter
    if (testTruck.calculateRentalRate(5) == (100.0 * 5 + 80.0)) {
        cout << "Constructor and Getter Test PASSED\n";
    } else {
        cout << "Constructor and Getter Test FAILED\n";
    }

    // Test Rental Rate Calculation
    if (testTruck.calculateRentalRate(5) == 580.0) {  // 5 days * 100 + 50 (additional fee)
        cout << "Rental Rate Calculation Test - 5 days PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 5 days FAILED\n";
    }

    if (testTruck.calculateRentalRate(1) == 180.0) {  // 1 day * 100 + 50 (additional fee)
        cout << "Rental Rate Calculation Test - 1 day PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 1 day FAILED\n";
    }

    if (testTruck.calculateRentalRate(0) == 80.0) {  // 0 days * 100 + 50 (additional fee)
        cout << "Rental Rate Calculation Test - 0 days PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 0 days FAILED\n";
    }

    // Test Display Details
    cout << "\nTesting Display Details:\n";
    testTruck.displayDetails();  // Display the truck's information

    // Edge Case: Truck with no additional fee (only base rate)
    Truck testTruckNoFee(202, "Chevrolet", 2023, 2025, 3000, 0.0f);
    if (testTruckNoFee.calculateRentalRate(5) == 500.0) {  // 5 days * 100 + 0
        cout << "Edge Case Test - No Additional Fee PASSED\n";
    } else {
        cout << "Edge Case Test - No Additional Fee FAILED\n";
    }

    cout << "All tests completed.\n";

    return 0;
}

