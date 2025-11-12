#include <iostream>     
#include <stdexcept>    

// --- Підключаємо класи для Завдання 1 ---
#include "Rectangle.h"

// --- Підключаємо класи для Завдання 2 ---
// Нам достатньо підключити User.h, оскільки він
// по ланцюжку вже підключає Cart.h, а той - Product.h.
#include "User.h"

// (Можна також явно підключити всі, якщо вам так зрозуміліше)
// #include "Product.h"
// #include "Cart.h"


int main() {

    // --- Демонстрація Завдання 1: Прямокутник ---
    std::cout << "---= TASK 1: RECTANGLE =---" << std::endl;

    // Використовуємо try...catch, оскільки наш конструктор
    // та сеттер можуть "кинути" виняток std::invalid_argument
    try {
        // Створюємо об'єкт Rectangle
        Rectangle rect(0.0, 0.0, 4.0, 3.0);
        std::cout << "Rectangle created: (0,0) to (4,3)" << std::endl;

        // Викликаємо методи обчислень
        std::cout << "Diagonal length: " << rect.calculateDiagonal() << std::endl; // Очікуємо 5
        std::cout << "Perimeter: " << rect.calculatePerimeter() << std::endl;     // Очікуємо 14

        // Використовуємо метод встановлення полів
        rect.setFields(1.0, 1.0, 10.0, 5.0);
        std::cout << "\nRectangle fields set to: (1,1) to (10,5)" << std::endl;
        std::cout << "New Diagonal: " << rect.calculateDiagonal() << std::endl; // Очікуємо ~9.85
        std::cout << "New Perimeter: " << rect.calculatePerimeter() << std::endl;  // Очікуємо 26

        // Демонстрація некоректних даних (викличе помилку)
        // std::cout << "\nAttempting to set invalid fields..." << std::endl;
        // rect.setFields(5.0, 5.0, 5.0, 10.0); // Це призведе до винятку

    }
    catch (const std::invalid_argument& e) {
        // Відловлюємо та виводимо повідомлення про помилку
        std::cerr << "Error caught: " << e.what() << std::endl;
    }


    // --- Демонстрація Завдання 2: Користувач та Кошик ---
    std::cout << "\n\n---= TASK 2: USER, CART, PRODUCT =---" << std::endl;

    // 1. Створюємо товари (об'єкти класу Product)
    Product apple("Apple", 15.50);
    Product bread("Bread", 22.00);
    Product milk("Milk", 35.75);

    // 2. Створюємо користувача (об'єкт класу User)
    // Його кошик (Cart) створюється автоматично всередині нього
    User user1("Viktor");
    std::cout << "User created: " << user1.getUsername() << std::endl;

    // 3. Отримуємо доступ до кошика користувача і викликаємо його методи
    user1.getCart().AddToCart(apple);
    user1.getCart().AddToCart(bread);
    user1.getCart().AddToCart(milk);

    // 4. Перевіряємо вміст кошика та загальну суму
    user1.getCart().ShowItems();
    std::cout << "Total price: " << user1.getCart().CalculateTotal() << " UAH" << std::endl;

    // 5. Видаляємо товар
    std::cout << "\nRemoving Bread..." << std::endl;
    user1.getCart().RemoveFromCart(bread);

    // 6. Перевіряємо фінальний стан кошика
    user1.getCart().ShowItems();
    std::cout << "Final total price: " << user1.getCart().CalculateTotal() << " UAH" << std::endl;


    return 0; // Успішне завершення програми
}
