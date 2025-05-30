// --- main.cpp ---
#include <iostream>
#include <vector>
#include <limits>
#include <ctime>

#include "Car.h"
#include "Truck.h"
#include "ElectricCar.h"
#include "Customer.h"
#include "RentalManager.h"
#include "UIManager.h"

using namespace std;

// Helper function for validated integer input
int getValidatedInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value)
            break;
        cout << "\t\t\t\t\t\t\tInvalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

int main() {
    // Shared data vectors
    vector<Vehicle*> vehicles;
    vector<Customer*> customers;

    // Initialize manager and UI with shared vectors
    RentalManager manager(vehicles, customers);
    UIManager ui(manager);
    

    // Load existing customer data
    try {
        manager.loadCustomersFromFile("customers.txt");
    } catch (const exception& e) {
        cerr << "\t\t\t\t\t\t\tError loading customers: " << e.what() << endl;
    }

    manager.loadVehiclesFromFile("vehicles.txt");

    manager.loadRentalsFromFile("rentals.txt");
    // Show the main menu
    ui.showMenu();

    // Cleanup: deallocate memory
    for (Vehicle* v : vehicles) {
        delete v;
    }

    for (Customer* c : customers) {
        delete c;
    }

    return 0;
}