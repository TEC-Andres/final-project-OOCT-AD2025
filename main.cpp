#include "lib/product.h"
#include "lib/customer.h"
#include "lib/orders.h"
#include <iostream>
#include <string>

/*
Creates an array of Product objects (store inventory).
Displays the inventory using a loop.
Creates a Customer object.
Allows the customer to create an order:
Select multiple products by ID.
Input quantities.
Stop when the user enters 0.
Use decisions and loops to control logic.
Display an order summary with the total amount.
*/

int main() {
    // Create store inventory
    Product inventory[5] = {
        Product(1, "Xbox", 650.00, 10),
        Product(2, "PS5", 500.0, 20),
        Product(3, "Bose Headphones", 30.0, 50),
        Product(4, "TV 20*20 inches", 100.0, 15),
        Product(5, "Keyboard", 40.0, 30)
    };

    // Display inventory
    std::cout << "Store Inventory:" << std::endl;
    for (const auto& product : inventory) {
        product.printProduct();
        std::cout << "------------------------" << std::endl;
    }

    // Create a customer
    Customer customer(1, "John Doe", "john.doe@example.com");
    std::cout << "Customer Info:" << std::endl;
    customer.printCustomer();
    std::cout << "------------------------" << std::endl;
    // Create an order for the customer
    Order order(customer);
    int prodId, quantity;
    while (true) {
        std::cout << "Enter Product ID to add to order (0 to finish): ";
        std::cin >> prodId;
        if (prodId == 0) {
            break;
        }

        // Find product by ID
        Product* selectedProduct = nullptr;
        for (auto& product : inventory) {
            if (product.getId() == prodId) {
                selectedProduct = &product;
                break;
            }
        }

        if (selectedProduct) {
            std::cout << "Enter quantity for " << selectedProduct->getName() << ": ";
            std::cin >> quantity;
            order.addProduct(selectedProduct, quantity);
        } else {
            std::cout << "Product ID not found. Please try again." << std::endl;
        }
    }
    // Display order summary
    std::cout << "Order Summary:" << std::endl;
    order.showOrderSummary();
    std::cout << "Total Amount: $" << order.getTotal() << std::endl;

    return 0;
}