#include "Cart.h"
#include <iostream>
#include <algorithm> // Для std::find_if
#include <numeric>   // Для std::accumulate (альтернатива для CalculateTotal)

// Конструктор
Cart::Cart() {
    // Кошик створюється порожнім, вектор 'products' ініціалізується автоматично
}

// 2. Метод AddToCart(Product p) - додати товар
void Cart::AddToCart(const Product& p) {
    products.push_back(p);
    std::cout << "Product added: " << p.getName() << std::endl;
}

// 2. Метод RemoveFromCart(Product p) - видалити товар
void Cart::RemoveFromCart(const Product& p_to_remove) {
    auto it = std::find_if(products.begin(), products.end(),
        [&](const Product& p) {
            return p.getName() == p_to_remove.getName();
        });

    if (it != products.end()) {
        std::cout << "Product removed: " << it->getName() << std::endl;
        products.erase(it);
    }
    else {
        std::cout << "Product not found in cart: " << p_to_remove.getName() << std::endl;
    }
}

// 2. Метод CalculateTotal() - загальна сума
double Cart::CalculateTotal() const {
    double total = 0.0;
    for (const auto& p : products) {
        total += p.getPrice();
    }
    return total;
}

// Допоміжний метод
void Cart::ShowItems() const {
    std::cout << "--- Cart Items ---" << std::endl;
    if (products.empty()) {
        std::cout << "Cart is empty." << std::endl;
        return;
    }
    for (const auto& p : products) {
        std::cout << "- " << p.getName() << " (" << p.getPrice() << " UAH)" << std::endl;
    }
    std::cout << "------------------" << std::endl;
}
