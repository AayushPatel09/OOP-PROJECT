#include <iostream>
#include "Customer.h"

using namespace std;

int main() {
    // Test 1: Create a Customer using the auto-assigned ID constructor
    Customer customer1("John Doe", 1234567890);
    
    cout << "Test 1: Auto-assigned ID Constructor\n";
    cout << "Customer ID: " << customer1.getID() << "\n";  // Should print 1 (nextID is 1 initially)
    cout << "Name: " << customer1.getName() << "\n";  // Should print "John Doe"
    cout << "Phone: 1234567890\n";  // Should print the phone number passed to the constructor
    customer1.getDetails();  // Display customer details
    
    // Test 2: Create another Customer with an explicit ID
    Customer customer2(5, "Jane Smith", 9876543);
    
    cout << "\nTest 2: Explicit ID Constructor\n";
    cout << "Customer ID: " << customer2.getID() << "\n";  // Should print 5 (explicit ID)
    cout << "Name: " << customer2.getName() << "\n";  // Should print "Jane Smith"
    cout << "Phone: 9876543\n";  // Should print the phone number passed to the constructor
    customer2.getDetails();  // Display customer details
    
    // Test 3: Create a Customer and update the contact info (phone)
    customer1.updateContactInfo(1122334455);  // Update phone number for customer1
    
    cout << "\nTest 3: Update Contact Info\n";
    cout << "Customer ID: " << customer1.getID() << "\n";  // Should print 1 (same as before)
    cout << "Updated Phone: 1122334455\n";  // Should reflect the updated phone number
    customer1.getDetails();  // Display customer details after update
    
    // Test 4: Check nextID to verify the customer ID system works correctly
    cout << "\nTest 4: Checking nextID\n";
    cout << "Next Available ID (should be 6): " << Customer::nextID << "\n";  // nextID should be 6 after creating customer2 with ID 5
    
    cout << "All tests completed.\n";

    return 0;
}
