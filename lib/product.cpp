#include "product.h"
#include <iostream>

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

void Product::printProduct() const {
    std::cout << "Product ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Stock: " << stock << std::endl;
}

bool Product::reduceStock(int qty) {
    if (qty <= 0) return false;
    if (qty > stock) return false;
    stock -= qty;
    return true;
}