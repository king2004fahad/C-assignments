#include <iostream>

class Rectangle {
private:
    double width;
    double length;

public:
    // Default constructor
    Rectangle() {
        width = 0.0;
        length = 0.0;
    }

    // Parameterized constructor
    Rectangle(double w, double l) {
        width = w;
        length = l;
    }

    // Setters (Mutators)
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        }
    }

    void setLength(double l) {
        if (l > 0) {
            length = l;
        }
    }

    // Getters (Accessors)
    double getWidth() const {
        return width;
    }

    double getLength() const {
        return length;
    }

    // Calculate Area
    double calculateArea() const {
        return width * length;
    }

    // Calculate Perimeter
    double calculatePerimeter() const {
        return 2 * (width + length);
    }
};

int main() {
    // Example 1: Creating a rectangle and setting dimensions manually
    Rectangle rect1;
    rect1.setWidth(5.5);
    rect1.setLength(10.0);

    std::cout << "--- Rectangle 1 ---" << std::endl;
    std::cout << "Width: " << rect1.getWidth() << std::endl;
    std::cout << "Length: " << rect1.getLength() << std::endl;
    std::cout << "Area: " << rect1.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rect1.calculatePerimeter() << std::endl;
    std::cout << std::endl;

    // Example 2: Creating a rectangle using the parameterized constructor
    Rectangle rect2(7.0, 4.0);

    std::cout << "--- Rectangle 2 ---" << std::endl;
    std::cout << "Width: " << rect2.getWidth() << std::endl;
    std::cout << "Length: " << rect2.getLength() << std::endl;
    std::cout << "Area: " << rect2.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rect2.calculatePerimeter() << std::endl;
    std::cout << std::endl;

    // Example 3: Modifying an existing rectangle
    rect2.setWidth(8.0);
    rect2.setLength(8.0);
    
    std::cout << "--- Rectangle 2 (After Modification) ---" << std::endl;
    std::cout << "New Width: " << rect2.getWidth() << std::endl;
    std::cout << "New Length: " << rect2.getLength() << std::endl;
    std::cout << "New Area: " << rect2.calculateArea() << std::endl;
    
    return 0;
}
