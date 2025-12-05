#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
/*
Product Class

Models a product in the online store.
Attributes (private):

id
name
price
stock
Methods (public):

Default and parameterized constructors
setId(), setName(), setPrice(), setStock()
getId(), getName(), getPrice(), getStock()
void printProduct() – display product details.
*/

class Product {
private:
    int id;
    std::string name;
    double price;
    int stock;    

public:
    Product(); // Default constructor
    Product(int prodId, const std::string& prodName, double prodPrice, int prodStock); // Parameterized constructor
    void setId(int prodId);
    void setName(const std::string& prodName);
    void setPrice(double prodPrice);
    void setStock(int prodStock);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getStock() const;

    void printProduct() const; // display product details.
};

#endif // PRODUCT_H