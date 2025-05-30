#include <iostream>
#include <string>
#include"Car.h"

using namespace std;

int main() {
    // Create a car object for testing
    Car testCar(123, "Toyota", 2023, 2025, 60.0f);

    // Test Constructor and Getter
    if (testCar.getBaseRate() == 60.0f) {
        cout << "Constructor and Getter Test PASSED\n";
    } else {
        cout << "Constructor and Getter Test FAILED\n";
    }

    // Test Rental Rate Calculation
    if (testCar.calculateRentalRate(5) == 300.0) {
        cout << "Rental Rate Calculation Test - 5 days PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 5 days FAILED\n";
    }

    if (testCar.calculateRentalRate(1) == 60.0) {
        cout << "Rental Rate Calculation Test - 1 day PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 1 day FAILED\n";
    }

    if (testCar.calculateRentalRate(0) == 0.0) {
        cout << "Rental Rate Calculation Test - 0 days PASSED\n";
    } else {
        cout << "Rental Rate Calculation Test - 0 days FAILED\n";
    }

    // Edge Case: Base rate 0
    Car testCarZero(124, "Honda", 2023, 2025, 0.0f);
    if (testCarZero.calculateRentalRate(10) == 0.0) {
        cout << "Edge Case Test - Base rate 0 for 10 days PASSED\n";
    } else {
        cout << "Edge Case Test - Base rate 0 for 10 days FAILED\n";
    }

    if (testCarZero.calculateRentalRate(100) == 0.0) {
        cout << "Edge Case Test - Base rate 0 for 100 days PASSED\n";
    } else {
        cout << "Edge Case Test - Base rate 0 for 100 days FAILED\n";
    }

    // Edge Case: Negative base rate
    Car testCarNegative(125, "Ford", 2023, 2025, -50.0f);
    if (testCarNegative.calculateRentalRate(5) == -250.0) {
        cout << "Edge Case Test - Negative base rate for 5 days PASSED\n";
    } else {
        cout << "Edge Case Test - Negative base rate for 5 days FAILED\n";
    }

    cout << "All tests completed.\n";

    return 0;
}
