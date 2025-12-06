#ifndef ORDERS_H
#define ORDERS_H

#pragma once
#include "customer.h"
#include "product.h"
#include "..\colorLib\parentTerminal.h"
#include "_globals.h"
/*
Represents a customer’s order.
This class demonstrates composition: thus, it contains both Customer and Product objects.

Attributes (private):

customer : Customer
orderedProducts[10] : Product
quantities[10] : int
orderCount : int
total : double
Methods (public):

Constructors
addProduct method
calculateTotal method
showOrderSummary method
getTotal method
*/

class Order {
private:
    Customer customer;
    Product orderedProducts[10];
    int quantities[10];
    int orderCount;
    double total;

public:
    Order(); // Default constructor
    Order(const Customer& cust); // Parameterized constructor

    bool addProduct(Product& product, int quantity);
    float calculateTotal();
    void showOrderSummary() const;
    double getTotal() const;
};

#endif // ORDERS_H