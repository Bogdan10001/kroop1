#include "User.h"

// Конструктор ініціалізує ім'я, 
// а 'cart' автоматично викликає свій конструктор за замовчуванням
User::User(const std::string& name) : username(name) {}

std::string User::getUsername() const {
    return username;
}

// Повертаємо посилання на 'cart', щоб main міг викликати cart.AddToCart()
Cart& User::getCart() {
    return cart;
}
