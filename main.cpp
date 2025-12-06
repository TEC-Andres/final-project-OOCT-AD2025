#define NOMINMAX
#include <iostream>
#include <string>
#include <limits>
#include <thread>
#include <chrono>

#include "lib/product.h"
#include "lib/customer.h"
#include "lib/orders.h"
#include "lib/preamble.h"
#include "colorLib/parentTerminal.h"
#include "lib/_globals.h"

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
    Preamble preamble;

    Product inventory[5] = {
        Product(1, "Xbox", 650.00, 10),
        Product(2, "PS5", 500.0, 20),
        Product(3, "Bose Headphones", 30.0, 50),
        Product(4, "TV 20*20 inches", 100.0, 15),
        Product(5, "Keyboard", 40.0, 30)
    };

    Customer customer[4] = {
        Customer(101, "Alejandro Salinas", "a01287454@tec.mx"),
        Customer(102, "Andres Rodriguez", "a01287002@tec.mx"),
        Customer(103, "Vicente Isaac Roldan", "a01287176@tec.mx"),
        Customer(104, "Iker Cossio", "a01283181@tec.mx")
    };

    Customer* selectedCustomer = nullptr;
    while (true) {
        auto [custName, custId, custEmail] = preamble.clientData();
        custName = preamble.capitalizeName(custName);

        for (auto& cust : customer) {
            if (
                preamble.checkIfClientDataExists(custName) &&
                cust.getName() == custName &&
                cust.getId() == custId &&
                cust.getEmail() == custEmail
            ) {
                selectedCustomer = &cust;
                break;
            }
        }

        if (selectedCustomer) {
            selectedCustomer->printCustomer();
            std::cout << std::endl;
            break;
        } else {
            terminal.printColor(hConsole, 0xFF0000, "The customer data you entered does not match any record. Please try again.\n");
        }
    }
    Order order(*selectedCustomer);
    int prodId, quantity;
    while (true) {
        std::cout << "=== Store Inventory ===" << std::endl;
        for (const auto& product : inventory) {
            product.printProduct();
            std::cout << "------------------------" << std::endl;
        }


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
        if (selectedProduct && 
            (std::cout << "Enter quantity for " << selectedProduct->getName() << ": ", std::cin >> quantity, 
             quantity > 0 && quantity <= selectedProduct->getStock())) {
            order.addProduct(*selectedProduct, quantity);
            terminal.printColor(hConsole, 0x00FF00, "Product added to order successfully!\n");
        } else {
            terminal.printColor(hConsole, 0xFF0000, selectedProduct ? 
            "Invalid quantity. Please enter a value between 1 and %d.\n" : 
            "Product ID not found. Please try again.\n", 
            selectedProduct ? selectedProduct->getStock() : 0);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
        preamble.clear();
    }

    terminal.printColor(hConsole, 0x00FF00, "\nOrder placed successfully!\n");

    order.showOrderSummary();

    return 0;
}