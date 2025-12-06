#include "orders.h"
#include <iostream>

Order::Order() : orderCount(0), total(0.0) {}
Order::Order(const Customer& cust) : customer(cust), orderCount(0), total(0.0) {}

/**
 * Adds a product and its quantity to the order.
 * Checks if there is enough stock before adding.
 */
void Order::addProduct(Product& product, int quantity) {
    if (orderCount >= 10) {
        std::cout << "Order limit reached. Cannot add more products." << std::endl;
        return;
    }

    if (quantity <= 0) {
        std::cout << "Invalid quantity. Must be at least 1." << std::endl;
        return;
    }

    // Check and reduce stock before adding to the order
    if (!product.reduceStock(quantity)) {
        std::cout << "Not enough stock for product '" << product.getName()
                  << "'. Available: " << product.getStock()
                  << ". Requested: " << quantity << "." << std::endl;
        return;
    }

    orderedProducts[orderCount] = product; // store a copy to compose Product in Order
    quantities[orderCount] = quantity;
    orderCount++;
}

/**
 * Calculates the total amount for the order by summing up the price of each product multiplied by its quantity.
 */
void Order::calculateTotal() {
    total = 0.0;
    for (int i = 0; i < orderCount; ++i) {
        total += orderedProducts[i].getPrice() * quantities[i];
    }
}

/**
 * Displays a summary of the order, including product details, quantities, subtotals, and the total amount.
 * If the total amout is over $5000, a discount of 10% is applied.
 */
void Order::showOrderSummary() const {
    double sumTotal = 0.0;
    std::cout << "Order Summary for Customer: " << customer.getName() << std::endl;
    for (int i = 0; i < orderCount; ++i) {
        double subtotal = orderedProducts[i].getPrice() * quantities[i];
        sumTotal += subtotal;
        std::cout << "Product: " << orderedProducts[i].getName()
                  << ", Quantity: " << quantities[i]
                  << ", Price per unit: $" << orderedProducts[i].getPrice()
                  << ", Subtotal: $" << subtotal
                  << std::endl;
    }
    if (sumTotal > 5000.0) {
        double discount = sumTotal * 0.10;
        sumTotal -= discount;
        std::cout << "Discount Applied: $" << discount << std::endl;
    }

    std::cout << "Total Amount: $" << sumTotal << std::endl;
}

double Order::getTotal() const {
    return total;
}

