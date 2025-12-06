#include "customer.h"
#include <iostream>

Customer::Customer() : id(0), name(""), email("") {}
Customer::Customer(int custId, const std::string& custName, const std::string& custEmail)
    : id(custId), name(custName), email(custEmail) {}

void Customer::setId(int id) {
    this->id = id;
}

void Customer::setName(const std::string& name) {
    this->name = name;
}

void Customer::setEmail(const std::string& email) {
    this->email = email;
}

int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getEmail() const {
    return email;
}

/**
 * display customer info.
 */
void Customer::printCustomer() const {
    std::cout << "Welcome back, " << name << "!" << std::endl;
    std::cout << "Your customer ID: " << id << std::endl;
    std::cout << "Your email: " << email << std::endl;
}