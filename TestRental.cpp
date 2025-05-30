#include <iostream>
#include <ctime>
#include <iomanip>
#include "Rental.h"
#include "Customer.h"
#include "Car.h" // Using Car subclass for concrete testing

using namespace std;

int main() {
    // Test 1: Create a Customer and Vehicle (Car) objects
    Customer customer1("Alice", 1234567890);  // Customer with ID auto-assigned to 1
    Car car1(101, "Toyota", 2023, 2025, 50.0);  // Concrete Car object with ID 101

    // Set rental start and end dates (e.g., 3 days rental period)
    time_t startDate = time(0);  // Current time
    time_t endDate = startDate + (3 * 24 * 60 * 60);  // 3 days later

    // Create a Rental object
    Rental rental1(1, &car1, &customer1, startDate, endDate);
    
    // Test 2: Test calculateTotal() method
    double totalCost = rental1.calculateTotal();
    if (totalCost == 50.0 * 3) {  // 3 days * $50 per day
        cout << "Test 2: Total Cost Calculation PASSED\n";
    } else {
        cout << "Test 2: Total Cost Calculation FAILED\n";
    }

    // Test 3: Test getCustomer() method
    Customer* customer = rental1.getCustomer();
    if (customer->getID() == 1) {  // customer1 has ID 1
        cout << "Test 3: Get Customer PASSED\n";
    } else {
        cout << "Test 3: Get Customer FAILED\n";
    }

    // Test 4: Test printReceipt() method (This will just print output)
    cout << "\nTest 4: Printing Rental Receipt\n";
    rental1.printReceipt();

    // Test 5: Test Edge Case - 0 days rental (Same start and end date)
    time_t startDateZero = time(0);
    Rental rentalZero(2, &car1, &customer1, startDateZero, startDateZero);
    double totalCostZero = rentalZero.calculateTotal();
    if (totalCostZero == 0) {  // 0 days should result in $0 cost
        cout << "Test 5: Edge Case (0 days rental) PASSED\n";
    } else {
        cout << "Test 5: Edge Case (0 days rental) FAILED\n";
    }

    cout << "\nAll tests completed.\n";

    return 0;
}
