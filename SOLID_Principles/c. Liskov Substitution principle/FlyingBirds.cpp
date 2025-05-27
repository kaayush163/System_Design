#include <iostream>
#include <memory>
#include <vector>

// Base Bird class
class Bird {
public:
    virtual void eat() const {
        std::cout << "This bird is eating.\n";
    }

    virtual ~Bird() = default;
};

// Interface for flying capability
class IFlyingBird {
public:
    virtual void fly() const = 0;
    virtual ~IFlyingBird() = default;
};

// Sparrow is a Bird and can fly
class Sparrow : public Bird, public IFlyingBird {
public:
    void fly() const override {
        std::cout << "Sparrow is flying.\n";
    }

    void eat() const override {
        std::cout << "Sparrow is eating seeds.\n";
    }
};

// Penguin is a Bird but cannot fly
class Penguin : public Bird {
public:
    void eat() const override {
        std::cout << "Penguin is eating fish.\n";
    }
};

// Utility functions
void letBirdEat(const Bird& bird) {
    bird.eat();
}

void letBirdFly(const IFlyingBird& flyingBird) {
    flyingBird.fly();
}

int main() {
    Sparrow sparrow;
    Penguin penguin;

    // All birds can eat
    letBirdEat(sparrow);
    letBirdEat(penguin);

    // Only flying birds can fly
    letBirdFly(sparrow);

   // letBirdFly(penguin); // ❌ This won't compile, which is good - LSP preserved!

    return 0;
}

