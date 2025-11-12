#include "Rectangle.h"
#include <iostream>

// Реалізація конструктора
Rectangle::Rectangle(double r_x1, double r_y1, double r_x2, double r_y2) {
    // Використовуємо наш сеттер, щоб одразу виконати перевірку
    setFields(r_x1, r_y1, r_x2, r_y2);
}

// Внутрішній метод валідації
bool Rectangle::areCoordinatesValid(double cx1, double cy1, double cx2, double cy2) const {
    // Перевіряємо, чи x та y координати не збігаються (щоб це не була лінія або точка)
    return (cx1 != cx2) && (cy1 != cy2);
}

// Реалізація сеттера
void Rectangle::setFields(double new_x1, double new_y1, double new_x2, double new_y2) {
    if (areCoordinatesValid(new_x1, new_y1, new_x2, new_y2)) {
        x1 = new_x1;
        y1 = new_y1;
        x2 = new_x2;
        y2 = new_y2;
    }
    else {
        // Якщо дані некоректні, кидаємо виняток
        throw std::invalid_argument("Error: Invalid coordinates. Rectangle cannot be a line or a point.");
    }
}

// --- Геттери ---
double Rectangle::getX1() const { return x1; }
double Rectangle::getY1() const { return y1; }
double Rectangle::getX2() const { return x2; }
double Rectangle::getY2() const { return y2; }

// --- Обчислення ---
double Rectangle::calculateDiagonal() const {
    // Використовуємо теорему Піфагора: d = sqrt((x2-x1)^2 + (y2-y1)^2)
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double Rectangle::calculatePerimeter() const {
    // P = 2 * (ширина + висота)
    double width = std::abs(x2 - x1);
    double height = std::abs(y2 - y1);
    return 2 * (width + height);
}
