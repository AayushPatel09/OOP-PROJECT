#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int customerID;       // Unique ID assigned to each customer
    std::string name;     // Name of the customer
    int phone;            // Phone number of the customer

public:
    static int nextID;    // Static variable to keep track of the next available customer ID

    // Constructor to create a new customer with auto-generated ID
    Customer(std::string name, int phone);

    // Constructor to create a customer with a specific ID (used when loading from file)
    Customer(int customerID, std::string name, int phone);

    // Displays customer details
    void getDetails();

    // Updates the customer's phone number
    void updateContactInfo(int phone);

    // Returns the customer's name
    std::string getName();

    // Returns the customer's unique ID
    int getID() const;
};

#endif // CUSTOMER_H