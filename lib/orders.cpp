#include "orders.h"
#include <iostream>

Order::Order() : orderCount(0), total(0.0) {}
Order::Order(const Customer& cust) : customer(cust), orderCount(0), total(0.0) {}

void Order::addProduct(Product* product, int quantity) {
    if (orderCount < 10) {
        orderedProducts[orderCount] = product;
        quantities[orderCount] = quantity;
        orderCount++;
    } else {
        std::cout << "Order limit reached. Cannot add more products." << std::endl;
    }
}

void Order::calculateTotal() {
    total = 0.0;
    for (int i = 0; i < orderCount; ++i) {
        total += orderedProducts[i]->getPrice() * quantities[i];
    }
}

void Order::showOrderSummary() const {
    std::cout << "Order Summary for Customer: " << customer.getName() << std::endl;
    for (int i = 0; i < orderCount; ++i) {
        std::cout << "Product: " << orderedProducts[i]->getName()
                  << ", Quantity: " << quantities[i]
                  << ", Price per unit: $" << orderedProducts[i]->getPrice()
                  << ", Subtotal: $" << orderedProducts[i]->getPrice() * quantities[i]
                  << std::endl;
    }
    std::cout << "Total Amount: $" << total << std::endl;
}

double Order::getTotal() const {
    return total;
}

