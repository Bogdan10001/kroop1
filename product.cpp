#include "Product.h"

Product::Product(const std::string& prod_name, double prod_price)
    : name(prod_name), price(prod_price) {
    // Тіло конструктора залишається порожнім, 
    // оскільки ініціалізація відбувається у списку ініціалізаторів
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}
