#include <iostream>
#include <string>
#include <memory>

// Abstract Prototype
class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() const = 0;
    virtual Shape* clone() const = 0;
};

// Concrete Prototype: Circle
class Circle : public Shape {
private:
    int radius;

public:
    Circle(int r) : radius(r) {}
    Circle(const Circle& other) : radius(other.radius) {}

    void draw() const override {
        std::cout << "Drawing Circle with radius " << radius << "\n";
    }

    Shape* clone() const override {
        return new Circle(*this);
    }
};

// Concrete Prototype: Rectangle
class Rectangle : public Shape {
private:
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}
    Rectangle(const Rectangle& other) : width(other.width), height(other.height) {}

    void draw() const override {
        std::cout << "Drawing Rectangle with width " << width << " and height " << height << "\n";
    }

    Shape* clone() const override {
        return new Rectangle(*this);
    }
};

// Client Code
int main() {
    // Original objects
    Shape* circle = new Circle(10);
    Shape* rectangle = new Rectangle(5, 7);

    // Cloning
    Shape* anotherCircle = circle->clone();
    Shape* anotherRectangle = rectangle->clone();

    // Drawing all shapes
    circle->draw();
    rectangle->draw();
    anotherCircle->draw();
    anotherRectangle->draw();

    return 0;
}

