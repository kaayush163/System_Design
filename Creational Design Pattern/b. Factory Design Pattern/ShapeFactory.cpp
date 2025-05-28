
// Abstract product class
#include <bits/stdc++.h>;
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {
    } // Virtual destructor for polymorphism
};
// Concrete product class - Circle
class Circle : public Shape {
public:
    void draw() override
    {
        std::cout<<"Drawing a Circle"<<std::endl;
    }
};

// Concrete product class - Square
class Square : public Shape {
public:
    void draw() override
    {
        std::cout<<"Drawing a Square"<<std::endl;
    }
};
// Abstract creator class
class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() {
    } // Virtual destructor for polymorphism
};
// Concrete creator class - CircleFactory
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override { return new Circle(); }
};

// Concrete creator class - SquareFactory
class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override { return new Square(); }
};
int main()
{
    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();

    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();

    circle->draw(); // Output: Drawing a Circle
    square->draw(); // Output: Drawing a Square

    delete circleFactory;
    delete squareFactory;
    delete circle;
    delete square;

      // Client code based on user-input

      /* cout << "Enter shape type (circle or square): ";
    string shapeType;
    cin >> shapeType;

    ShapeFactory* shapeFactory = nullptr;
    if (shapeType == "circle") {
        shapeFactory = new CircleFactory();
    } else if (shapeType == "square") {
        shapeFactory = new SquareFactory();
    } else {
        cout << "Invalid shape type entered." << endl;
        return 1;
    }

    Shape* shape = shapeFactory->createShape();
    shape->draw();

    delete shapeFactory;
    delete shape; */

    return 0;
}
