#include "orders.h"
#include <iostream>

Order::Order() : orderCount(0), total(0.0) {}
Order::Order(const Customer& cust) : customer(cust), orderCount(0), total(0.0) {}

/**
 * Adds a product and its quantity to the order.
 * Checks if there is enough stock before adding.
 */
bool Order::addProduct(Product& product, int quantity) {
    const int MAX_QUANTITY_PER_ITEM = 10;

    if (quantity <= 0) {
        terminal.printColor(hConsole, 0xFF0000, "Invalid quantity. Must be at least 1.\n");
        return false;
    }

    // Check if this product is already in the order
    int existingIndex = -1;
    for (int i = 0; i < orderCount; ++i) {
        if (orderedProducts[i].getName() == product.getName()) {
            existingIndex = i;
            break;
        }
    }

    int currentQuantity = (existingIndex != -1) ? quantities[existingIndex] : 0;
    if (currentQuantity + quantity > MAX_QUANTITY_PER_ITEM) {
        terminal.printColor(hConsole, 0xFF0000, "Cannot add more than %d units of '%s' to the order.\n", MAX_QUANTITY_PER_ITEM, product.getName().c_str());
        return false;
    }

    // Check and reduce stock before adding to the order
    if (!product.reduceStock(quantity)) {
        terminal.printColor(hConsole, 0xFF0000, "Not enough stock for product '%s'. Available: %d. Requested: %d.\n", product.getName().c_str(), product.getStock(), quantity);
        return false;
    }

    if (existingIndex != -1) {
        quantities[existingIndex] += quantity;
    } else {
        orderedProducts[orderCount] = product;
        quantities[orderCount] = quantity;
        orderCount++;
    }
    return true;
}

/**
 * Calculates the total amount for the order by summing up the price of each product multiplied by its quantity.
 */
float Order::calculateTotal() {
    total = 0.0;
    for (int i = 0; i < orderCount; ++i) {
        total += orderedProducts[i].getPrice() * quantities[i];
    }
    if (total > 2000.0) {
        terminal.printColor(hConsole, 0x00FF00, "A 10%% discount has been applied to your order for exceeding $2000!\n");
        total -= total * 0.10;
    }

    return static_cast<float>(total);
}

/**
 * Displays a summary of the order, including product details, quantities, subtotals, and the total amount.
 * If the total amout is over $5000, a discount of 10% is applied.
 */
void Order::showOrderSummary() const {
    std::cout << "Order Summary for Customer: " << customer.getName() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < orderCount; ++i) {
        double subtotal = orderedProducts[i].getPrice() * quantities[i];
        std::cout << "Product: " << orderedProducts[i].getName()
                  << ", Quantity: " << quantities[i]
                  << ", Price per unit: $" << orderedProducts[i].getPrice()
                  << ", Subtotal: $" << subtotal
                  << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl << std::endl;


    float total = const_cast<Order*>(this)->calculateTotal();
    terminal.printColor(hConsole, 0xFFFF00, "Total Amount: $%.2f\n", total);
}

double Order::getTotal() const {
    return total;
}

