#include "product.h"
#include <iostream>
#include <sstream>

Product::Product() : id(0), name(""), price(0.0), stock(0) {}
Product::Product(int prodId, const std::string& prodName, double prodPrice, int prodStock)
    : id(prodId), name(prodName), price(prodPrice), stock(prodStock) {}

void Product::setId(int id) {
    this-> id = id;
}

void Product::setName(const std::string& name) {
    this-> name = name;
}

void Product::setPrice(double price) {
    this-> price = price;
}

void Product::setStock(int stock) {
    this-> stock = stock;
}

int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return stock;
}

/**
 * display product details. A.k.a, ID, Name, Price, Stock
 * this is done in a fancy way with colors using ParentTerminal class
 */
void Product::printProduct() const {
    const char* labels[] = {"ID", "Name", "Price", "Stock"};
    const char* formats[] = {"%s", "%s", "$%s", "%s"};

    std::string idStr = std::to_string(id);
    std::ostringstream oss;
    oss.setf(std::ios::fixed);
    oss.precision(2);
    oss << price;
    std::string priceStr = oss.str();
    std::string stockStr = std::to_string(stock);

    const void* values[] = {idStr.c_str(), name.c_str(), priceStr.c_str(), stockStr.c_str()};

    terminal.prettyDisplay(hConsole, 0xAFAFAF, labels, formats, values, 4);
}

/**
 * Reduces the stock by the specified quantity if enough stock is available.
 * Returns true if the stock was successfully reduced, false otherwise.
 */
bool Product::reduceStock(int qty) {
    if (qty <= 0) return false;
    if (qty > stock) return false;
    stock -= qty;
    return true;
}