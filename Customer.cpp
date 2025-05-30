#include<iostream>
#include"Customer.h"
using namespace std;
// Constructor with auto-assigned ID
Customer::Customer(std::string name, int phone) {
    this->customerID = nextID++;
    this->name = name;
    this->phone = phone;
}
int Customer::nextID = 1;
// Constructor with explicit ID 
Customer::Customer(int customerID, std::string name, int phone) {
    this->customerID = customerID;
    this->name = name;
    this->phone = phone;

    if (customerID >= nextID) {
        nextID = customerID + 1;  // ensure future IDs don’t collide
    }
}



void Customer::getDetails(){
    cout<<"\t\t\t\t\t\t\tYour ID : "<<customerID << "\n"<<"\t\t\t\t\t\t\tName: "<<name<< "\n" << "\t\t\t\t\t\t\tPhone : "<<phone<<endl;
}

void Customer::updateContactInfo(int phone){
    this->phone = phone;
}

string Customer::getName(){
    return name;

}

int Customer::getID() const {
    return customerID;
}