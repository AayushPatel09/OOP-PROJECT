#include"Vehicle.h"
#include<iostream>
#include<string>
using namespace std;

// Constructor with parameters to initialize vehicle data
Vehicle::Vehicle(int vehicleId , string brand , int model , int year , bool isRented){
    this->vehicleId = vehicleId;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->isRented = isRented;
}

// Default constructor
Vehicle::Vehicle(){}

// Display vehicle details to the console
void Vehicle::displayDetails(){
    cout << "\t\t\t\t\t\t\tVehicle id is : " << vehicleId << endl;
    cout << "\t\t\t\t\t\t\tVehicle brand is : " << brand << endl;
    cout << "\t\t\t\t\t\t\tVehicle model is : " << model << endl;
    cout << "\t\t\t\t\t\t\tVehicle year is : " << year << endl;
    if(isRented == 0){
        cout << "\t\t\t\t\t\t\tVehicle is avialble" << endl;
    }
    else{
        cout << "\t\t\t\t\t\t\tVehicle is not available"<< endl;
    }
}

// Rent the vehicle if not already rented, return success status
bool Vehicle::rentVehicle(){
    if(!isRented){
        isRented = true;
        std::cout << "\t\t\t\t\t\t\tVehicle " << vehicleId << " rented successfully." << std::endl;
        return true;
    }
    else{
        std::cout << "\t\t\t\t\t\t\tVehicle " << vehicleId << " is already rented." << std::endl;
        return false;
    }
}

// Return the vehicle if rented, return success status
bool Vehicle::returnvehicle(){
    if (isRented) {
        isRented = false;
        std::cout << "\t\t\t\t\t\t\tVehicle " << vehicleId << " returned successfully." << std::endl;
        return true;
    } else {
        std::cout << "\t\t\t\t\t\t\tVehicle " << vehicleId << " is not currently rented." << std::endl;
        return false;
    }
}

// Get the vehicle's ID
int Vehicle::getVehicleId(){
    return vehicleId;
}

// Check if vehicle is available (not rented)
bool Vehicle::isAvailable() const {
    return !isRented;
}

// Mark the vehicle as rented (used internally)
void Vehicle::markAsRented() {
    isRented = true;
}