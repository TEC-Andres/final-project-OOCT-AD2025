#define NOMINMAX
#include "lib/product.h"
#include "lib/customer.h"
#include "lib/orders.h"
#include <iostream>
#include <string>
#include "colorLib/parentTerminal.h"
#include <limits>

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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ParentTerminal terminal;

    Product inventory[5] = {
        Product(1, "Xbox", 650.00, 10),
        Product(2, "PS5", 500.0, 20),
        Product(3, "Bose Headphones", 30.0, 50),
        Product(4, "TV 20*20 inches", 100.0, 15),
        Product(5, "Keyboard", 40.0, 30)
    };

    std::cout << "=== Store Inventory ===" << std::endl;
    /**
     * 
     * 
     * 
     * */
    for (const auto& product : inventory) {
        product.printProduct();
        std::cout << "------------------------" << std::endl;
    }

    // Collect customer data
    std::string custName, custEmail;
    std::cout << "\n=== Customer Information ===" << std::endl;
    std::cout << "Enter your name: ";
    std::getline(std::cin, custName);
    std::cout << "Enter your email: ";
    std::getline(std::cin, custEmail);
    std::cout << "------------------------" << std::endl;

    Customer customer(1, custName, custEmail);
    std::cout << "Customer Info:" << std::endl;
    customer.printCustomer();
    std::cout << "------------------------" << std::endl;

    Order order(customer);
    int prodId, quantity;
    while (true) {
        std::cout << "Enter Product ID to add to order (0 to finish): ";
        if (!(std::cin >> prodId)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            terminal.printColor(hConsole, 0xFF0000, "Invalid input. Please enter a valid Product ID.\n");
            continue;
        }

        if (prodId == 0) {
            break;
        }

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
            if (quantity <= 0 || quantity > selectedProduct->getStock()) {
            terminal.printColor(hConsole, 0xFF0000, "Invalid quantity. Please enter a value between 1 and %d.\n", selectedProduct->getStock());
            continue;
            }
            order.addProduct(selectedProduct, quantity);
            terminal.printColor(hConsole, 0x00FF00, "Product added to order successfully!\n");
        } else {
            terminal.printColor(hConsole, 0xFF0000, "Product ID not found. Please try again.\n");
        }
    }

    terminal.printColor(hConsole, 0x00FF00, "\nOrder placed successfully!\n");

    std::cout << "Order Summary:" << std::endl;
    order.showOrderSummary();

    return 0;
}