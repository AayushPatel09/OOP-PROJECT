#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    protected:
    int vehicleId;
    string brand;
    int model;
    int year;
    bool isRented;
    public:
    Vehicle();
    Vehicle(int vehicleId , string brand , int model , int year , bool isRented);
    void displayDetails();
    virtual double calculateRentalRate(int days) const = 0;
    bool rentVehicle();
    bool returnvehicle();
    int getVehicleId();
    bool isAvailable() const;  
    void markAsRented();  // marks vehicle as rented without printing
    virtual ~Vehicle() {}


};

#endif // VEHICLE_H