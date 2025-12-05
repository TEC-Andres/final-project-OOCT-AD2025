#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "_globals.h"
/*
Customer Class

Represents a customer using the digital platform.
Attributes (private):

id
name
email
Methods (public):

Constructors
Setters and getters for each attribute
void printCustomer() – display customer info.
*/

class Customer { 
private:
    int id;
    std::string name;
    std::string email;

public:
    Customer(); // Default constructor
    Customer(int custId, const std::string& custName, const std::string& custEmail); // Parameterized constructor
    void setId(int custId);
    void setName(const std::string& custName);
    void setEmail(const std::string& custEmail);

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;

    void printCustomer() const; // display customer info.
};

#endif // CUSTOMER_H