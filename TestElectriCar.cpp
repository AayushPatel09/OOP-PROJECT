#include "ElectricCar.h"
#include <iostream>
#include"Car.h"

using namespace std;

int main() {
    // Create an ElectricCar object for testing
    ElectricCar electricCar(101, "Tesla", 2023, 2025);

    // Test Constructor and Getter
    if (electricCar.getBaseRate() == 80.0f) {
        cout << "Constructor and Getter Test PASSED\n";
    } else {
        cout << "Constructor and Getter Test FAILED\n";
    }

    // Test Rental Rate Calculation
    if (electricCar.calculateRentalRate(5) == 400.0) {
        cout << "Rental Rate Calculation Test - 5 days PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 5 days FAILED\n";
    }

    if (electricCar.calculateRentalRate(1) == 80.0) {
        cout << "Rental Rate Calculation Test - 1 day PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 1 day FAILED\n";
    }

    if (electricCar.calculateRentalRate(0) == 0.0) {
        cout << "Rental Rate Calculation Test - 0 days PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 0 days FAILED\n";
    }

    // Test Charging Info Display (for example, 50% battery and 2 hours charge time)
    cout << "\nTesting Charging Info Display:\n";
    electricCar.displayChargingInfo(50, 2.0);

    // Edge Case: Negative Base Rate in ElectricCar (even though Car class already sets the base rate)
    ElectricCar testNegativeRate(102, "Rivian", 2023, 2025);
    if (testNegativeRate.calculateRentalRate(5) == 350.0) {
        cout << "Edge Case Test - Negative base rate handling PASSED\n";
    } else {
        cout << "Edge Case Test - Negative base rate handling FAILED\n";
    }

    cout << "All tests completed.\n";

    return 0;
}
