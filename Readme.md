# VEHICLE RENTAL MANAGEMENT SYSTEM

## Table of Contents

- Project Description
- Features
- Technologies Used
- Installation and Setup
- How to Use
- File Structure
- Planned Features
- Credits

## Project Description

The *Vehicle Rental Management System* is a console-based C++ system which is designed to simulate a real-world vehicle rental service. It allows users to register customers, view and rent available vehicles (Cars, Trucks, Electric Cars), return them, and view rental histories. The project demonstrates key Object Orineted Programming concepts such as inheritance, polymorphism, aggregation, exeption handling and STL. It also include other programming concepts like file handling, dynamic memory management, and input validation.

This system is suitable for learning and practicing fundamental software engineering principles and is structured in a modular, maintainable, and extendable manner.

---

---

## Features

- View available vehicles
- Rent a vehicle
- Return a vehicle using Rental ID
- Register a new customer
- View customer rental history
- Save and load rental and customer data from text files
- File-based persistence for data longevity

---

## Technologies Used

- C++11 version
- Object-Oriented Programming
- File I/O (ifstream/ofstream)
- Input validation with <regex> and <limits>
- Use of STL containers like std::vector

---

## Installation and Setup

To install and run the project on your local system:

1. Clone the repository or download the source code.
2. Ensure you have a C++ compiler installed (like g++ or Visual Studio).

### Compile the project:

To compile, use the following compilation syntax:
*g++ -std=c++11 main.cpp Vehicle.cpp Car.cpp Truck.cpp ElectricCar.cpp Rental.cpp Customer.cpp RentalManager.cpp UIManager.cpp Utils.cpp -o RentalSystem*

---

## How to Use:

1. When you launch the program, a menu will display multiple options.
2. Choose an option by entering a number from 1 to 7.
3. Follow the prompts to:
   - View vehicles
   - Rent or return a vehicle
   - View rental history
   - Register new customers
4. All data is stored and updated in external text files.

---

### Sample Credentials

No credentials are required. Customer IDs and phone numbers are generated and validated during registration as per as user input.

---

## File Structure

VehicleRentalSystem/
├── Car.h / Car.cpp
├── Truck.h / Truck.cpp
├── ElectricCar.h / ElectricCar.cpp
├── Vehicle.h / Vehicle.cpp
├── Customer.h / Customer.cpp
├── Rental.h / Rental.cpp
├── RentalManager.h / RentalManager.cpp
├── UIManager.h / UIManager.cpp
├── Utils.h / Utils.cpp
├── main.cpp
├── vehicles.txt # Preloaded vehicle data
├── customers.txt # Registered customer data
├── rentals.txt # Saved rentals
└── README.md # Project documentation

---

## Planned Features

- Add login authentication for admin and customers
- GUI implementation using a framework like Qt or SFML
- Add rental statistics and usage reports
- Include rental duration customization with pricing tiers

---

## Credits

Aayush Patel

### Developer:

https://github.com/AayushPatel09/OOP-PROJECT.git

Thank you for using the Vehicle Rental System
